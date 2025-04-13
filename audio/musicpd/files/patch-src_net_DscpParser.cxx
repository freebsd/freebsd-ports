--- src/net/DscpParser.cxx.orig	2025-03-11 10:05:29 UTC
+++ src/net/DscpParser.cxx
@@ -9,7 +9,10 @@
 #ifdef _WIN32
 #include <ws2tcpip.h>
 #else
-#include <netinet/ip.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #endif
 
 #ifndef IPTOS_DSCP_AF11
