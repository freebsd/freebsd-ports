--- libwaitress/src/waitress.c.orig	2010-10-07 01:54:32.000000000 -0700
+++ libwaitress/src/waitress.c	2010-10-08 14:51:41.000000000 -0700
@@ -21,9 +21,6 @@
 THE SOFTWARE.
 */
 
-#define _POSIX_C_SOURCE 1 /* required by getaddrinfo() */
-#define _BSD_SOURCE /* snprintf() */
-
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
