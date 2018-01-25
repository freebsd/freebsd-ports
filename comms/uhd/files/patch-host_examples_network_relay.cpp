--- host/examples/network_relay.cpp.orig	2017-12-17 19:37:02.232333000 +0000
+++ host/examples/network_relay.cpp	2017-12-17 19:37:35.331222000 +0000
@@ -128,5 +128,5 @@
         std::vector<char> buff(insane_mtu);
         while (not boost::this_thread::interruption_requested()){
-            if (wait_for_recv_ready(_server_socket->native())){
+            if (wait_for_recv_ready(_server_socket->native_handle())){
                 boost::mutex::scoped_lock lock(_endpoint_mutex);
                 const size_t len = _server_socket->receive_from(asio::buffer(&buff.front(), buff.size()), _endpoint);
@@ -154,5 +154,5 @@
         std::vector<char> buff(insane_mtu);
         while (not boost::this_thread::interruption_requested()){
-            if (wait_for_recv_ready(_client_socket->native())){
+            if (wait_for_recv_ready(_client_socket->native_handle())){
                 const size_t len = _client_socket->receive(asio::buffer(&buff.front(), buff.size()));
                 boost::mutex::scoped_lock lock(_endpoint_mutex);
