--- Sources/Network/Socket/socket_name.cpp.orig	2014-04-05 12:47:48.000000000 +0200
+++ Sources/Network/Socket/socket_name.cpp	2014-04-05 12:50:09.000000000 +0200
@@ -34,6 +34,7 @@
 #ifdef WIN32
 typedef unsigned long in_addr_t;
 #else
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
