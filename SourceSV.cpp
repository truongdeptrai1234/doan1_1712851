#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <wchar.h>
#include <stdlib.h>

#define max 50

 struct SINHVIEN{
	wchar_t MSSV[max];
	wchar_t HoVaTen[max];
	wchar_t khoa[max];
	wchar_t truong[max];
	wchar_t ngaySinh[max];
	wchar_t hinhAnhCaNhan[max];
	wchar_t email[max];
	wchar_t MoTa[100];
	wchar_t soThich[100];
	int namhoc;
} ;
	//Ghi file HTML
 void ghi(SINHVIEN *SV,FILE* p){
	
	 int m = 0; int n = 0;
	 wchar_t set[256]; wchar_t *create;
	 int a[max], l = 0,count=0;
	 fseek(p, 3L, SEEK_SET);
	 while (fgetws(set, 255, p) != NULL)
	 {
		 create = wcstok(set, L",");
		 wcscpy(SV[m].MSSV, create);
		 create = wcstok(NULL, L",");
		 SV[m].namhoc = _wtoi(create);
		 create = wcstok(NULL, L",");
		 wcscpy(SV[m].HoVaTen, create);
		 create = wcstok(NULL, L",");
		 
		 wcscpy(SV[m].truong, create);
		 create = wcstok(NULL, L",");
		 wcscpy(SV[m].ngaySinh, create);
		 create = wcstok(NULL, L",");
		 wcscpy(SV[m].email, create);
		 create = wcstok(NULL, L",");
		 wcscpy(SV[m].hinhAnhCaNhan, create);
		 create = wcstok(NULL, L",");
		 wcscpy(SV[m].MoTa, create);
		 
		 n = 0;
		 while (true){
			 create = wcstok(NULL, L",");
			 if (create == NULL)
				 break;
			 wcscpy( SV[m].soThich, create);
			 n++;
		 }
		 a[l] = n;
		 l++;
		 wprintf(L"\n");
		 m++;

	 }
	 wprintf(L"\n");
	
	 for (int stt = 1; stt < m; stt++)
		 {
			 
			 wchar_t namefile[max];
			 wcscpy(namefile, SV[stt].MSSV);
			 wcscat(namefile, L".html");
			 wchar_t filepage[max];
			 wcscpy(filepage, L"WEBSITE/");wcscat(filepage, namefile);
			 FILE*htm = _wfopen(filepage, L"wt,ccs=UTF-8");
			 fwprintf(htm, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
			 fwprintf(htm, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
			 fwprintf(htm, L"	   <head>\n");
			 fwprintf(htm, L"        <meta http-equiv=\"Content-Type\" content=\"text/html; charset = utf-8\" />\n");
			 fwprintf(htm, L"        <link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
			 fwprintf(htm, L"        <title>HCMUS - %s</title>\n", SV[stt].HoVaTen);
			 fwprintf(htm, L"    </head>\n");
			 fwprintf(htm, L"    <body>\n");
			 fwprintf(htm, L"        <div class=\"Layout_container\">\n");
			 fwprintf(htm, L"            <!-- Begin Layout Banner Region -->\n");
			 fwprintf(htm, L"            <div class=\"Layout_Banner\" >\n");
			 fwprintf(htm, L"                <div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
			 fwprintf(htm, L"                <div class=\"Header_Title\">TRUỜNG ÐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n");
			 fwprintf(htm, L"            </div>\n");
			 fwprintf(htm, L"            <!-- End Layout Banner Region -->\n");
			 fwprintf(htm, L"            <!-- Begin Layout MainContents Region -->\n");
			 fwprintf(htm, L"            <div class=\"Layout_MainContents\">\n");
			 fwprintf(htm, L"                <!-- Begin Below Banner Region -->\n");
			 fwprintf(htm, L"                <div class=\"Personal_Main_Information\">\n");
			 fwprintf(htm, L"                    <!-- Begin Thông tin cá nhân  ----------------------------------------------------------------------------------------- -->\n");
			 fwprintf(htm, L"                    <div class=\"Personal_Location\">\n");
			 fwprintf(htm, L"                        <img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
			 fwprintf(htm, L"                        <span class=\"Personal_FullName\">%s - %s</span>\n", SV[stt].HoVaTen, SV[stt].MSSV);
			 fwprintf(htm, L"                        <div class=\"Personal_Department\">%s</div>\n", SV[stt].khoa);
			 fwprintf(htm, L"                        <br />\n");
			 fwprintf(htm, L"                        <div class=\"Personal_Phone\">\n");
			 fwprintf(htm, L"                        Email: %s\n", SV[stt].email);
			 fwprintf(htm, L"                        </div>\n");
			 fwprintf(htm, L"                        <br />\n");
			 fwprintf(htm, L"                        <br />\n");
			 fwprintf(htm, L"                    </div>\n");
			 fwprintf(htm, L"                    <!-- End Thông tin cá nhân  ----------------------------------------------------------------------------------------- -->\n");
			 fwprintf(htm, L"                    <div class=\"Personal_HinhcanhanKhung\">\n");
			 fwprintf(htm, L"                        <img src=\"Images/%s\" class=\"Personal_Hinhcanhan\" />\n", SV[stt].hinhAnhCaNhan);
			 fwprintf(htm, L"                    </div>\n");
			 fwprintf(htm, L"                </div>\n");
			 fwprintf(htm, L"                <!-- End Below Banner Region -->\n");
			 fwprintf(htm, L"                <!-- Begin MainContents Region -->\n");
			 fwprintf(htm, L"                <div class=\"MainContain\">\n");
			 fwprintf(htm, L"                <!-- Begin Top Region -->\n");
			 fwprintf(htm, L"                    <div class=\"MainContain_Top\">\n");
			 fwprintf(htm, L"                        <div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
			 fwprintf(htm, L"                        <div>\n");
			 fwprintf(htm, L"                            <ul class=\"TextInList\">\n");
			 fwprintf(htm, L"                                <li>Họ và tên: %s</li>\n", SV[stt].HoVaTen);
			 fwprintf(htm, L"                                <li>MSSV: %s</li>\n", SV[stt].MSSV);
			 fwprintf(htm, L"                                <li>Sinh viên khoa: %s</li>\n", SV[stt].khoa);
			 fwprintf(htm, L"                                <li>Ngày sinh: %s</li>\n", SV[stt].ngaySinh);
			 fwprintf(htm, L"                                <li>Email: %s</li>\n", SV[stt].email);
			 fwprintf(htm, L"                            </ul>\n");
			 fwprintf(htm, L"                        </div>\n");
			 fwprintf(htm, L"                        <div class=\"InfoGroup\">Sở thích</div>\n");
			 fwprintf(htm, L"                        <div>\n");
			 fwprintf(htm, L"                            <ul class=\"TextInList\">\n");
			 for (int h = 0; h < a[count]; h++){
				 fwprintf(htm, L"                                <li>%s</li>\n", SV[stt].soThich[h]);
			 }
			 fwprintf(htm, L"                            </ul>\n");
			 fwprintf(htm, L"                        </div>\n");
			 fwprintf(htm, L"                        <div class=\"InfoGroup\">Mô tả</div>\n");
			 fwprintf(htm, L"                        <div class=\"Description\">\n");
			 fwprintf(htm, L"                            %s.\n", SV[stt].MoTa);
			 fwprintf(htm, L"                        </div>\n");
			 fwprintf(htm, L"                    </div>\n");
			 fwprintf(htm, L"                </div>\n");
			 fwprintf(htm, L"            </div>\n");
			 fwprintf(htm, L"            <!-- Begin Layout Footer -->\n");
			 fwprintf(htm, L"            <div class=\"Layout_Footer\">\n");
			 fwprintf(htm, L"                <div class=\"divCopyright\">\n");
			 fwprintf(htm, L"                    <br />\n");
			 fwprintf(htm, L"                    <img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
			 fwprintf(htm, L"                    <br />\n");
			 fwprintf(htm, L"                    @2013</br>\n");
			 fwprintf(htm, L"                    Ðồ án giữa kì</br>\n");
			 fwprintf(htm, L"                Kỹ thuật lập trình</br>\n");
			 fwprintf(htm, L"                TH2012/03</br>\n");
			 fwprintf(htm, L"                %s - %s</br>\n", SV[stt].MSSV, SV[stt].HoVaTen);
			 fwprintf(htm, L"                </div>\n");
			 fwprintf(htm, L"            </div>\n");
			 fwprintf(htm, L"            <!-- End Layout Footer -->\n");
			 fwprintf(htm, L"        </div>\n");
			 fwprintf(htm, L"    </body>\n");
			 fwprintf(htm, L"</html>\n");
			 count++;

		 }

		 wprintf(L"--done--\n");
	 }
 
 void main(){
	 _setmode(_fileno(stdout), _O_U16TEXT);
	 _setmode(_fileno(stdin), _O_U16TEXT);
	 struct SINHVIEN *SV;
	 SV = new SINHVIEN[sizeof(SINHVIEN)];
	 FILE*p = _wfopen(L"truong.csv", L"r,ccs=UTF-8");
	 ghi(SV, p);
	 fclose(p);
	 free(SV);
	 getch();
 }

