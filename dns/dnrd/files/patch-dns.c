--- src/dns.c	Thu Jan  4 10:37:21 2001
+++ src/dns.c.new	Sat Mar 10 14:29:38 2001
@@ -27,6 +27,7 @@
 #include <ctype.h>
 
 #include <netdb.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
