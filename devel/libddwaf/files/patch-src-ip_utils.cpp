--- src/ip_utils.cpp.orig	2023-01-17 18:39:22 UTC
+++ src/ip_utils.cpp
@@ -22,6 +22,7 @@
 
 #  include <ws2tcpip.h>
 #else
+#  include <sys/socket.h>
 #  include <arpa/inet.h>
 #  include <netinet/in.h>
 #endif
