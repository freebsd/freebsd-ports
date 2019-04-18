--- src/core/tsi/ssl_transport_security.cc.orig	2019-04-15 23:12:51 UTC
+++ src/core/tsi/ssl_transport_security.cc
@@ -22,6 +22,7 @@
 
 #include "src/core/tsi/ssl_transport_security.h"
 
+#include <sys/socket.h>
 #include <limits.h>
 #include <string.h>
 
