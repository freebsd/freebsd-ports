--- src/mba/time.h.orig	Tue Mar 22 08:58:04 2005
+++ src/mba/time.h	Tue Mar 22 08:56:02 2005
@@ -20,7 +20,7 @@
 #endif /* WIN32 */
 #endif /* LIBMBA_API */
 
-#if defined(__sparc__)
+#if defined(__sparc__) && ! (defined (__FreeBSD__))
   #include <sys/inttypes.h>
 #elif defined(_WIN32)
   #define MILLISECONDS_BETWEEN_1970_AND_1601 11644473600000Ui64
