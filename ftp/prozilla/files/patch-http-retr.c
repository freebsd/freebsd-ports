--- src/http-retr.c.ori	Sat Jan 25 00:49:21 2003
+++ src/http-retr.c	Sat Jan 25 00:49:34 2003
@@ -32,6 +32,7 @@
 #include <fcntl.h>
 #include <sys/socket.h>
 #include <sys/time.h>
+#include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
