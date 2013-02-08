--- binutils/winduni.c.orig	Fri Jun  8 01:15:17 2012
+++ binutils/winduni.c	Fri Jun  8 01:17:33 2012
@@ -85,7 +85,7 @@
   { 1258, "WINDOWS-1258" },
   { CP_UTF7, "UTF-7" },
   { CP_UTF8, "UTF-8" },
-  { CP_UTF16, "UTF-16" },
+  { CP_UTF16, "UTF-16LE" },
   { (rc_uint_type) -1, NULL }
 };
 
@@ -682,7 +682,7 @@
 
   if (!mb || !iconv_name)
     return 0;
-  iconv_t cd = iconv_open ("UTF-16", iconv_name);
+  iconv_t cd = iconv_open ("UTF-16LE", iconv_name);
 
   while (1)
     {
@@ -755,7 +755,7 @@
 
   if (!u || !iconv_name)
     return 0;
-  iconv_t cd = iconv_open (iconv_name, "UTF-16");
+  iconv_t cd = iconv_open (iconv_name, "UTF-16LE");
 
   while (1)
     {
