--- src/main.cpp.orig	2003-05-03 09:46:15 UTC
+++ src/main.cpp
@@ -27,11 +27,11 @@ int host_byte_order;
 
 //Ê¸»úÎó
 #ifdef __FreeBSD__
-#define LANG "ja_JP.EUC"
+#define LANG "ja_JP.eucJP"
 #else
 #define LANG "ja_JP"
 #endif
-#define VERSION_NAME "jmode out of the way! Version "VERSION"\n"
+#define VERSION_NAME "jmode out of the way! Version " VERSION "\n"
 char *version_name=VERSION_NAME;
 char *usage=
 "--help , --version :Show usage or version\n"
