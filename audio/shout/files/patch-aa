--- sock.c	Thu Apr 20 03:31:50 2000
+++ sock.c.new	Wed Jun 14 15:43:59 2000
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
