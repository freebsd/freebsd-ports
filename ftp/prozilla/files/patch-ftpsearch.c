--- src/ftpsearch.c.ori	Sat Jan 25 00:45:38 2003
+++ src/ftpsearch.c	Sat Jan 25 00:45:48 2003
@@ -25,6 +25,7 @@
 #include <sys/socket.h>
 #include <fcntl.h>
 #include <netdb.h>
+#include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <arpa/inet.h>
