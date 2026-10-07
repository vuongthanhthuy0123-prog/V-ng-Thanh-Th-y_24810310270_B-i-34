#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Ngay
{
    int ngay;
    int thang;
    int nam;
};

struct NhanVien
{
    int maNV;
    string hoTen;
    Ngay ngaySinh;
    double luong;
};

void Nhap(NhanVien a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap nhan vien thu " << i + 1 << ":\n";

        cout << "Ma nhan vien: ";
        cin >> a[i].maNV;
        cin.ignore();

        cout << "Ho ten: ";
        getline(cin, a[i].hoTen);

        cout << "Ngay sinh:\n";

        cout << "  Ngay: ";
        cin >> a[i].ngaySinh.ngay;

        cout << "  Thang: ";
        cin >> a[i].ngaySinh.thang;

        cout << "  Nam: ";
        cin >> a[i].ngaySinh.nam;

        cout << "Luong (trieu dong): ";
        cin >> a[i].luong;
    }
}

void Xuat(NhanVien a[], int n)
{
    cout << "\n";

    cout << left
         << setw(10) << "Ma NV"
         << setw(25) << "Ho ten"
         << setw(15) << "Ngay sinh"
         << setw(15) << "Luong"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left
             << setw(10) << a[i].maNV
             << setw(25) << a[i].hoTen;

        if (a[i].ngaySinh.ngay < 10)
            cout << "0";

        cout << a[i].ngaySinh.ngay << "/";

        if (a[i].ngaySinh.thang < 10)
            cout << "0";

        cout << a[i].ngaySinh.thang << "/";

        cout << a[i].ngaySinh.nam;

        cout << setw(6) << " ";

        cout << fixed << setprecision(2)
             << setw(15) << a[i].luong
             << endl;
    }
}

void BubbleSort(NhanVien a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j].luong > a[j + 1].luong)
            {
                NhanVien temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void TimKiem(NhanVien a[], int n, double X)
{
    int trai = 0;
    int phai = n - 1;
    int viTri = -1;

    while (trai <= phai)
    {
        int mid = (trai + phai) / 2;

        if (a[mid].luong == X)
        {
            viTri = mid;
            break;
        }
        else if (a[mid].luong < X)
        {
            trai = mid + 1;
        }
        else
        {
            phai = mid - 1;
        }
    }

    if (viTri == -1)
    {
        cout << "\nKhong tim thay nhan vien co luong = "
             << fixed << setprecision(2) << X
             << " (trieu dong)." << endl;

        return;
    }

    int dau = viTri;

    while (dau > 0 && a[dau - 1].luong == X)
    {
        dau--;
    }

    int cuoi = viTri;

    while (cuoi < n - 1 && a[cuoi + 1].luong == X)
    {
        cuoi++;
    }

    cout << "\nCAC NHAN VIEN CO LUONG = "
         << fixed << setprecision(2) << X
         << " (TRIEU DONG):" << endl;

    cout << left
         << setw(10) << "Ma NV"
         << setw(25) << "Ho ten"
         << setw(15) << "Ngay sinh"
         << setw(15) << "Luong"
         << endl;

    for (int i = dau; i <= cuoi; i++)
    {
        cout << left
             << setw(10) << a[i].maNV
             << setw(25) << a[i].hoTen;

        if (a[i].ngaySinh.ngay < 10)
            cout << "0";

        cout << a[i].ngaySinh.ngay << "/";

        if (a[i].ngaySinh.thang < 10)
            cout << "0";

        cout << a[i].ngaySinh.thang << "/";

        cout << a[i].ngaySinh.nam;

        cout << setw(6) << " ";

        cout << fixed << setprecision(2)
             << setw(15) << a[i].luong
             << endl;
    }
}

int main()
{
    NhanVien a[100];

    int n;
    double X;

    cout << "Nhap so luong nhan vien n = ";
    cin >> n;

    while (n <= 0 || n > 100)
    {
        cout << "Nhap lai n (0 < n <= 100): ";
        cin >> n;
    }

    Nhap(a, n);

    cout << "\nDANH SACH NHAN VIEN VUA NHAP";
    Xuat(a, n);

    BubbleSort(a, n);

    cout << "\nDANH SACH SAU KHI SAP XEP TANG DAN THEO LUONG";
    Xuat(a, n);

    cout << "\nNhap luong X can tim (trieu dong): ";
    cin >> X;

    TimKiem(a, n, X);

    return 0;
}
