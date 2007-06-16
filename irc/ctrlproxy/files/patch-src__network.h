--- src/network.h.orig	Sun Apr 15 14:17:58 2007
+++ src/network.h	Sat Jun 16 11:46:55 2007
@@ -30,8 +30,11 @@
 #endif
 
 #include "state.h"
+#include <sys/types.h>
 #include "isupport.h"
 #include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 
 #define DEFAULT_NETWORK_CHARSET NULL
 
