--- uds/streamsocket.cc.orig	Thu Sep  5 02:38:14 2002
+++ uds/streamsocket.cc	Thu Sep  5 02:38:24 2002
@@ -25,6 +25,7 @@
 #include "config.h"
 #ifdef HAVE_SOCKET
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <sys/un.h>
