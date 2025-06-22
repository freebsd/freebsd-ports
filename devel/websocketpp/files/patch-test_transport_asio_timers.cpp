--- test/transport/asio/timers.cpp.orig	2020-04-19 18:25:17 UTC
+++ test/transport/asio/timers.cpp
@@ -54,7 +54,7 @@ void run_dummy_server(int port) {
     using boost::asio::ip::tcp;
 
     try {
-        boost::asio::io_service io_service;
+        boost::asio::io_context io_service;
         tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v6(), port));
         tcp::socket socket(io_service);
 
@@ -79,7 +79,7 @@ void run_test_timer(long value) {
 
 // Wait for the specified time period then fail the test
 void run_test_timer(long value) {
-    boost::asio::io_service ios;
+    boost::asio::io_context ios;
     boost::asio::deadline_timer t(ios,boost::posix_time::milliseconds(value));
     boost::system::error_code ec;
     t.wait(ec);
