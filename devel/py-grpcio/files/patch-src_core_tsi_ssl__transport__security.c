--- src/core/tsi/ssl_transport_security.c.orig	2017-10-26 17:03:10 UTC
+++ src/core/tsi/ssl_transport_security.c
@@ -20,6 +20,7 @@
 
 #include <grpc/support/port_platform.h>
 
+#include <sys/socket.h>
 #include <limits.h>
 #include <string.h>
 
