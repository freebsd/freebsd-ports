--- src/lib/net/CSocket.h.orig	Sun Feb  1 20:03:20 2004
+++ src/lib/net/CSocket.h	Sun Feb  8 22:48:23 2004
@@ -25,11 +25,11 @@
 #define __CSOCKET_H
 
 #include "gambas.h"
-#include <sys/types.h>
-#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/un.h>
+#include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <unistd.h>
 #include <netdb.h>
 #include "CDnsClient.h"
