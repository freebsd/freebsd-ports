--- src/network.h.orig	Fri Jan  5 06:33:07 2007
+++ src/network.h	Fri Jan  5 23:29:33 2007
@@ -30,7 +30,10 @@
 #endif
 
 #include "state.h"
+#include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 
 struct global;
 struct network;
