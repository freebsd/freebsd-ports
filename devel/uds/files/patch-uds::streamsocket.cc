--- uds/streamsocket.cc.orig	Thu May 10 19:59:24 2001
+++ uds/streamsocket.cc	Thu May 10 19:59:52 2001
@@ -25,6 +25,7 @@
 #include "config.h"
 #ifdef HAVE_SOCKET
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <sys/un.h>
 #include <uds/stdexcpt.hh>
