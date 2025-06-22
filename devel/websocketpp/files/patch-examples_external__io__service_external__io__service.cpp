--- examples/external_io_service/external_io_service.cpp.orig	2020-04-19 18:25:17 UTC
+++ examples/external_io_service/external_io_service.cpp
@@ -59,7 +59,7 @@ int main() {
 }
 
 int main() {
-    asio::io_service service;
+    asio::io_context service;
 
     // Add a TCP echo server on port 9003
     tcp_echo_server custom_http_server(service, 9003);
