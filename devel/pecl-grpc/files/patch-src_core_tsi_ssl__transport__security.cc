--- src/core/tsi/ssl_transport_security.cc.orig	2020-09-11 19:28:49 UTC
+++ src/core/tsi/ssl_transport_security.cc
@@ -20,6 +20,7 @@
 
 #include "src/core/tsi/ssl_transport_security.h"
 
+#include <sys/socket.h>
 #include <limits.h>
 #include <string.h>
 
