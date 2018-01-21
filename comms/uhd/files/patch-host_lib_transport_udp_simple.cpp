--- host/lib/transport/udp_simple.cpp.orig	2017-12-17 19:40:02.609104000 +0000
+++ host/lib/transport/udp_simple.cpp	2017-12-17 19:40:47.660730000 +0000
@@ -57,5 +57,5 @@
 
     size_t recv(const asio::mutable_buffer &buff, double timeout){
-        if (not wait_for_recv_ready(_socket->native(), timeout)) return 0;
+        if (not wait_for_recv_ready(_socket->native_handle(), timeout)) return 0;
         return _socket->receive_from(asio::buffer(buff), _recv_endpoint);
     }
