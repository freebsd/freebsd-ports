--- uds/sockbase.cc.orig	Thu May 10 19:57:08 2001
+++ uds/sockbase.cc	Thu May 10 19:57:26 2001
@@ -25,6 +25,7 @@
 #include "config.h"
 #ifdef HAVE_SOCKET
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/un.h>
