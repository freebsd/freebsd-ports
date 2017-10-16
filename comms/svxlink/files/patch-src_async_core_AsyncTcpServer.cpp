--- src/async/core/AsyncTcpServer.cpp.orig	2015-11-22 16:03:59 UTC
+++ src/async/core/AsyncTcpServer.cpp
@@ -198,7 +198,7 @@ TcpServer::TcpServer(const string& port_str, const Asy
   {
     addr.sin_addr = bind_ip.ip4Addr();
   }
-  if (bind(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) != 0)
+  if (::bind(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) != 0)
   {
     perror("bind");
     cleanup();
