--- Source/MessageExchangeDefinition/gdcmULConnectionInfo.cxx.orig	2012-01-02 10:31:32.000000000 +0100
+++ Source/MessageExchangeDefinition/gdcmULConnectionInfo.cxx	2012-01-02 10:32:31.000000000 +0100
@@ -28,6 +28,13 @@
 #include "gdcmULConnectionInfo.h"
 #include <socket++/sockinet.h>//for setting up the local socket
 
+#if defined (__FreeBSD__) // inet_addr
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#endif
+
 #if defined (__APPLE__)
 #include <arpa/inet.h> // inet_addr
 #endif
