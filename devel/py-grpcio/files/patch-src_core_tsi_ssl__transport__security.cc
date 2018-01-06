--- src/core/tsi/ssl_transport_security.cc.orig	2018-01-02 23:09:14 UTC
+++ src/core/tsi/ssl_transport_security.cc
@@ -20,6 +20,7 @@
 
 #include <grpc/support/port_platform.h>
 
+#include <sys/socket.h>
 #include <limits.h>
 #include <string.h>
 
