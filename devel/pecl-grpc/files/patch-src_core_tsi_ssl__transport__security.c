--- src/core/tsi/ssl_transport_security.c.orig	2017-08-29 09:34:33 UTC
+++ src/core/tsi/ssl_transport_security.c
@@ -35,6 +35,7 @@
 
 #include <grpc/support/port_platform.h>
 
+#include <sys/socket.h>
 #include <limits.h>
 #include <string.h>
 
