--- src/libwaitress/waitress.c.orig	2011-07-09 01:40:54.000000000 -0700
+++ src/libwaitress/waitress.c	2011-07-14 12:02:14.000000000 -0700
@@ -21,7 +21,6 @@
 THE SOFTWARE.
 */
 
-#define _POSIX_C_SOURCE 1 /* required by getaddrinfo() */
 #define _BSD_SOURCE /* snprintf() */
 
 #include <sys/types.h>
