--- uds/socket.cc.orig	Tue Feb 27 13:59:39 2001
+++ uds/socket.cc	Tue Feb 27 14:00:40 2001
@@ -25,6 +25,7 @@
 #include "config.h"
 #ifdef HAVE_SOCKET
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/un.h>
