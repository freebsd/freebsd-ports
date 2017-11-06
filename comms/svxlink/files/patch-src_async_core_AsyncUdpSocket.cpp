--- src/async/core/AsyncUdpSocket.cpp.orig	2015-11-22 16:03:59 UTC
+++ src/async/core/AsyncUdpSocket.cpp
@@ -189,7 +189,7 @@ UdpSocket::UdpSocket(uint16_t local_port, const IpAddr
     {
       addr.sin_addr = bind_ip.ip4Addr();
     }
-    if(bind(sock, reinterpret_cast<struct sockaddr *>(&addr), sizeof(addr))
+    if(::bind(sock, reinterpret_cast<struct sockaddr *>(&addr), sizeof(addr))
 	== -1)
     {
       perror("bind");
