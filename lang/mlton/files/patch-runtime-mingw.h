--- runtime/platform/mingw.h.orig	2008-04-27 10:54:07.000000000 +1000
+++ runtime/platform/mingw.h	2008-04-27 10:54:19.000000000 +1000
@@ -85,17 +85,6 @@
 #define SHUT_RDWR SD_BOTH
 
 /* ------------------------------------------------- */
-/*                       Date                        */
-/* ------------------------------------------------- */
-
-struct timezone {
-    int tz_dsttime;
-    int tz_minuteswest;
-};
-
-int gettimeofday (struct timeval *tv, struct timezone *tz);
-
-/* ------------------------------------------------- */
 /*                   MLton.Itimer                    */
 /* ------------------------------------------------- */
 
