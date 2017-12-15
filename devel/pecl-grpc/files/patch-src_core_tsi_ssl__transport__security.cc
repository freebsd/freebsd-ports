--- src/core/tsi/ssl_transport_security.cc.orig	2017-12-15 14:58:10 UTC
+++ src/core/tsi/ssl_transport_security.cc
@@ -19,7 +19,7 @@
 #include "src/core/tsi/ssl_transport_security.h"
 
 #include <grpc/support/port_platform.h>
-
+#include <sys/socket.h>
 #include <limits.h>
 #include <string.h>
 
