--- src/ftp-retr.c.ori	Sat Jan 25 00:40:45 2003
+++ src/ftp-retr.c	Sat Jan 25 00:40:56 2003
@@ -32,6 +32,7 @@
 #include <netdb.h>
 #include <sys/socket.h>
 #include <sys/time.h>
+#include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
