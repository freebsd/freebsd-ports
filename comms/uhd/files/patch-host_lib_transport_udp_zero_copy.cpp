--- host/lib/transport/udp_zero_copy.cpp.orig	2017-12-17 16:25:59.637675000 +0100
+++ host/lib/transport/udp_zero_copy.cpp	2017-12-17 16:26:12.713784000 +0100
@@ -191,5 +191,5 @@
         _socket->open(asio::ip::udp::v4());
         _socket->connect(receiver_endpoint);
-        _sock_fd = _socket->native();
+        _sock_fd = _socket->native_handle();
 
         //allocate re-usable managed receive buffers
