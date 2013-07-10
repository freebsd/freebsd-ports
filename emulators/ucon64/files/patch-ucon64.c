--- ucon64.c.orig	2005-01-06 15:43:44.000000000 -0800
+++ ucon64.c	2013-02-24 23:25:47.094966291 -0800
@@ -1394,17 +1394,7 @@
 #ifdef  DLOPEN
     ucon64.discmage_path;
 #else
-#if     defined __MSDOS__
-    "discmage.dxe";
-#elif   defined __CYGWIN__ || defined _WIN32
-    "discmage.dll";
-#elif   defined __APPLE__                       // Mac OS X actually
-    "libdiscmage.dylib";
-#elif   defined __unix__ || defined __BEOS__
-    "libdiscmage.so";
-#else
-    "unknown";
-#endif
+    "%%PREFIX%%/lib/libdiscmage.so";
 #endif
 
   if (!ucon64.discmage_enabled)
