#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sinhvien {
    char maSV[5];
    char Ten[50];
    char SoDt[15];
} sinhvien;
sinhvien SinhVien[100];

void Themsinhvien() {


    int i;
    for (i = 0; i < 1; ++i) {
        printf("nhap ten sinh vien thu %d\n", i + 1);
        fgets(SinhVien[i].Ten, sizeof(SinhVien[i].Ten) * sizeof(char), stdin);
        if (!strchr(SinhVien[i].Ten, '\n')) {
            while (fgetc(stdin) != '\n');
            SinhVien[i].Ten[strlen(SinhVien[i].Ten) - 1] = ' ';
        }
        printf("nhap ma sinh vien cua sinh vien thu %d\n", i + 1);
        fgets(SinhVien[i].maSV, sizeof(SinhVien[i].maSV) * sizeof(char), stdin);
        if (!strchr(SinhVien[i].maSV, '\n')) {
            while (fgetc(stdin) != '\n');
        }
        printf("nhap sdt sinh vien thu %d\n", i + 1);
        fgets(SinhVien[i].SoDt, sizeof(SinhVien[i].SoDt) * sizeof(char), stdin);
        if (!strchr(SinhVien[i].SoDt, '\n')) {
            while (fgetc(stdin) != '\n');
        }


        break;
    }
}

void Danhsachsinhvien() {

    printf("Ten :%s", SinhVien->Ten);
    printf("Ma sinh vien :%s", SinhVien->maSV);
    printf("So dien thoai :%s", SinhVien->SoDt);

}

void Luufile() {
    FILE *fp;

    fp = fopen("../danhsachsinhvien.txt", "w+");
    for (int j = 0; j < 2; ++j) {
        fprintf(fp, "%-20s|%-20s|%-20s\n", "Ten", "Ma sinh vien", "So dien thoai");
        fprintf(fp, "\n%-20s|%20s|%40s", SinhVien->Ten, SinhVien->maSV, SinhVien->SoDt);

    }
    fclose(fp);
}


void Docfile() {
    FILE *fp;
    char Danhsachsinhviencu[1000];
    fp = fopen("../danhsachsinhvien.txt", "r+");
    while (fgets(Danhsachsinhviencu, 1000, fp) != NULL) {
        printf("%s", Danhsachsinhviencu);
    }
    fclose(fp);
}

void Thoat() {
    int choice;
    printf("Ban co muon tiep tuc? (y/n)\n");
    scanf("%c", &choice);
    getchar();
    if (choice == 'y' || choice == 'Y') {
        exit(1);
    }
}

void menu() {
    int luachon;
    printf("Vui long nhap lua chon:\n");
    printf("1.Them moi sinh vien.\n");
    printf("2.Hien thi danh sach.\n");
    printf("3.Luu danh sach sinh vien ra file.\n");
    printf("4.Doc danh sach sinh vien tu file.\n");
    printf("5.Thoat chương trinh\n");

    scanf("%d", &luachon);
    getchar();
    switch (luachon) {
        case 1:
            Themsinhvien();
            menu();
            break;
        case 2:
            Danhsachsinhvien();
            menu();
            break;
        case 3:
            Luufile();
            menu();
            break;
        case 4:
            Docfile();
            menu();
            break;
        case 5:
            Thoat();
            break;
        default:
            printf("lua chon sai\n");

    }
}

int main() {
    menu();


    return 0;
}