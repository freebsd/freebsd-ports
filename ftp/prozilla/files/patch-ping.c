--- src/ping.c.ori	Sat Jan 25 00:53:13 2003
+++ src/ping.c	Sat Jan 25 00:53:28 2003
@@ -23,6 +23,7 @@
 #include <sys/socket.h>
 #include <fcntl.h>
 #include <netdb.h>
+#include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <arpa/inet.h>
