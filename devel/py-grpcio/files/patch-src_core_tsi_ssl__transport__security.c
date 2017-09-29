--- src/core/tsi/ssl_transport_security.c.orig	2017-09-27 21:43:56 UTC
+++ src/core/tsi/ssl_transport_security.c
@@ -20,6 +20,7 @@
 
 #include <grpc/support/port_platform.h>
 
+#include <sys/socket.h>
 #include <limits.h>
 #include <string.h>
 
