--- src/af_portability.h.old	Sat Mar 31 12:00:46 2001
+++ src/af_portability.h	Sat Mar 31 12:01:00 2001
@@ -2,6 +2,7 @@
 #define AF_PORTABILITY_H
 
 #include <netinet/in.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 
 /* _x_ must be a pointer to a sockaddr structure */
