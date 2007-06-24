--- src/fileinfo.cpp	Fri Apr 15 16:56:44 2005
+++ src/fileinfo.cpp	Sun Jun 24 06:02:55 2007
@@ -778,7 +778,7 @@
 void mac_file_info_box(char *filename)
 {
     char *title;
-
+    url2filename(filename);
     int nRetVal;
     wchar_t *pUTF16Name;
 
