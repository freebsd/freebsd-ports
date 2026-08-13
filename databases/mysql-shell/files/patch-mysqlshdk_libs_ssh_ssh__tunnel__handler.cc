--- mysqlshdk/libs/ssh/ssh_tunnel_handler.cc.orig	2026-01-26 17:02:55 UTC
+++ mysqlshdk/libs/ssh/ssh_tunnel_handler.cc
@@ -30,6 +30,12 @@
 #include <vector>
 #include "mysqlshdk/libs/utils/logger.h"
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 #ifndef MSG_NOSIGNAL
 #define MSG_NOSIGNAL 0
 #endif
