--- util.c.orig	2000-04-20 07:31:50 UTC
+++ util.c
@@ -18,8 +18,6 @@
 #include <process.h>
 #include <winbase.h>
 #else /*  *NIX  */
-#include <sys/socket.h>
-#include <netinet/in.h>
 #include <netdb.h>
 #include <fcntl.h>
 #include <sys/wait.h>
@@ -29,7 +27,6 @@
 #include <stdarg.h>
 #include <time.h>
 #include <errno.h>
-#include <arpa/inet.h>
 #include <sys/time.h>
 #include <unistd.h>
 #endif /* !win32 */
