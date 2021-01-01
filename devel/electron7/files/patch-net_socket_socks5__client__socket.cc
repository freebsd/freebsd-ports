--- net/socket/socks5_client_socket.cc.orig	2019-12-12 12:39:54 UTC
+++ net/socket/socks5_client_socket.cc
@@ -4,6 +4,10 @@
 
 #include "net/socket/socks5_client_socket.h"
 
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
+
 #include <utility>
 
 #include "base/bind.h"
