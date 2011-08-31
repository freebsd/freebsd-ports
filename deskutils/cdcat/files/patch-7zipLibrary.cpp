--- ../lib7zip/Lib7Zip/7zipLibrary.cpp.orig	2011-07-24 08:14:18.000000000 +0900
+++ ../lib7zip/Lib7Zip/7zipLibrary.cpp	2011-08-06 16:31:37.000000000 +0900
@@ -35,6 +35,13 @@
 #define HMODULE void *
 #endif
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#if (__FreeBSD_version < 900000 && __FreeBSD_version >= 800501) || (__FreeBSD_version >= 900006)
+#define HAVE_SCANDIR_POSIX
+#endif
+#endif
+
 /*-------------- const defines ---------------------------*/
 const UInt64 kMaxCheckStartPosition = 1 << 22;
 
@@ -819,7 +826,7 @@
 }
 #else
 
-#if defined(__WXMAC__) || defined(__APPLE__)
+#if defined(__WXMAC__) || defined(__APPLE__) || !defined(HAVE_SCANDIR_POSIX)
 int myselect(struct dirent * pDir );
 #else
 int myselect(const struct dirent * pDir );
@@ -856,7 +863,7 @@
     return true;
 }
 
-#if defined(__WXMAC__) || defined(__APPLE__)
+#if defined(__WXMAC__) || defined(__APPLE__) || !defined(HAVE_SCANDIR_POSIX)
 int myselect(struct dirent * pDir )
 #else
 int myselect(const struct dirent * pDir )
