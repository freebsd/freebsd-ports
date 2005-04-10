--- src/mba/time.h.orig	Sun Oct 26 06:06:09 2003
+++ src/mba/time.h	Sun Apr 10 22:27:40 2005
@@ -20,7 +20,9 @@
 #endif /* WIN32 */
 #endif /* LIBMBA_API */
 
-#if defined(__sparc__)
+#if defined(__FreeBSD__)
+  #include <inttypes.h>
+#elif defined(__sparc__)
   #include <sys/inttypes.h>
 #elif defined(_WIN32)
   #define MILLISECONDS_BETWEEN_1970_AND_1601 11644473600000Ui64
