--- src/ftp_listener.c.old	Sat Mar 31 12:01:10 2001
+++ src/ftp_listener.c	Sat Mar 31 12:01:24 2001
@@ -3,6 +3,7 @@
  */
 
 #include <config.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
