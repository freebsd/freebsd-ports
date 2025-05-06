--- indiserver/TcpServer.cpp.orig	2025-03-31 09:12:20 UTC
+++ indiserver/TcpServer.cpp
@@ -25,6 +25,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <fcntl.h>
+#include <sys/socket.h>
 
 TcpServer::TcpServer(int port): port(port)
 {
