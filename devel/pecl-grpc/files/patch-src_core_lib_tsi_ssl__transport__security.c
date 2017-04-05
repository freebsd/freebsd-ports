--- src/core/lib/tsi/ssl_transport_security.c.orig	2017-02-09 02:54:11 UTC
+++ src/core/lib/tsi/ssl_transport_security.c
@@ -35,6 +35,7 @@
 
 #include <grpc/support/port_platform.h>
 
+#include <sys/socket.h>
 #include <limits.h>
 #include <string.h>
 
