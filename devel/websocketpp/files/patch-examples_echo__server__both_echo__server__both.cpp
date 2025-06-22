--- examples/echo_server_both/echo_server_both.cpp.orig	2020-04-19 18:25:17 UTC
+++ examples/echo_server_both/echo_server_both.cpp
@@ -60,7 +60,7 @@ int main() {
 int main() {
     // set up an external io_service to run both endpoints on. This is not
     // strictly necessary, but simplifies thread management a bit.
-    boost::asio::io_service ios;
+    boost::asio::io_context ios;
 
     // set up plain endpoint
     server_plain endpoint_plain;
