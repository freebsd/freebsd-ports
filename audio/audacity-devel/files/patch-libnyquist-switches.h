--- lib-src/libnyquist/sys/switches.h.orig	Tue Dec  2 19:14:40 2003
+++ lib-src/libnyquist/sys/switches.h	Tue Dec  2 19:16:20 2003
@@ -39,7 +39,7 @@
 */
 #define nyquist_printf printf
 
-#if __APPLE__ && __GNUC__ /* Mac OS X */
+#if (__FreeBSD__ || __APPLE__) && __GNUC__ /* Mac OS X */
 #define NEED_ULONG 1
 #else
 #include <sys/types.h>
