--- host/lib/transport/tcp_zero_copy.cpp.orig	2017-12-17 19:39:49.890757000 +0000
+++ host/lib/transport/tcp_zero_copy.cpp	2017-12-17 19:40:36.125127000 +0000
@@ -155,5 +155,5 @@
         _socket.reset(new asio::ip::tcp::socket(_io_service));
         _socket->connect(receiver_endpoint);
-        _sock_fd = _socket->native();
+        _sock_fd = _socket->native_handle();
 
         //packets go out ASAP
