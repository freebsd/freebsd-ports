--- src/libwaitress/waitress.c.orig	2011-01-24 04:00:25.000000000 -0800
+++ src/libwaitress/waitress.c	2011-04-07 14:29:37.000000000 -0700
@@ -21,9 +21,6 @@
 THE SOFTWARE.
 */
 
-#define _POSIX_C_SOURCE 1 /* required by getaddrinfo() */
-#define _BSD_SOURCE /* snprintf() */
-
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
