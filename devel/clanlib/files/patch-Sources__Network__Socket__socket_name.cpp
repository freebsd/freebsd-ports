--- ./Sources/Network/Socket/socket_name.cpp.orig	2013-02-11 14:02:51.000000000 +0100
+++ ./Sources/Network/Socket/socket_name.cpp	2013-02-11 14:04:33.000000000 +0100
@@ -34,6 +34,7 @@
 #ifdef WIN32
 typedef unsigned long in_addr_t;
 #else
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
