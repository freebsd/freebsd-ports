--- rtosc/src/cpp/savefile.cpp.orig	2021-12-31 15:58:28 UTC
+++ rtosc/src/cpp/savefile.cpp
@@ -534,7 +534,7 @@ int load_from_file(const char* file_content,
     n = 0;
 
     sscanf(file_content,
-           "%% %128s v%u.%u.%u%n ", appbuf, &vma, &vmi, &vre, &n);
+           "%% %127s v%u.%u.%u%n ", appbuf, &vma, &vmi, &vre, &n);
     if(n <= 0 || strcmp(appbuf, appname) || vma > 255 || vmi > 255 || vre > 255)
         return -bytes_read-1;
 
