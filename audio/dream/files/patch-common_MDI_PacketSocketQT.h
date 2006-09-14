--- common/MDI/PacketSocketQT.h.orig	Wed Sep  6 15:40:23 2006
+++ common/MDI/PacketSocketQT.h	Wed Sep  6 15:40:51 2006
@@ -41,6 +41,8 @@
 #else
 # include <netinet/in.h>
 # include <arpa/inet.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #endif
 
 /* Some defines needed for compatibility when using Linux */
