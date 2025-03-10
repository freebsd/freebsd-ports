--- src/input_common/udp/client.cpp.orig	2025-02-16 22:55:21 UTC
+++ src/input_common/udp/client.cpp
@@ -109,7 +109,7 @@ class Socket { (private)
     }
 
     SocketCallback callback;
-    boost::asio::io_service io_service;
+    boost::asio::io_context io_service;
     boost::asio::basic_waitable_timer<clock> timer;
     udp::socket socket;
 
