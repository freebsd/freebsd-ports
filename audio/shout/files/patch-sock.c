--- sock.c.orig	2000-04-20 07:31:50 UTC
+++ sock.c
@@ -12,8 +12,10 @@
 #include <process.h>
 #include <winbase.h>
 #else /*  *NIX  */
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <netdb.h>
 #include <fcntl.h>
 #include <sys/wait.h>
@@ -22,7 +24,6 @@
 #include <ctype.h>
 #include <stdarg.h>
 #include <errno.h>
-#include <arpa/inet.h>
 #include <sys/time.h>
 #include <unistd.h>
 #endif /* !win32 */
