--- test/endpoint/endpoint.cpp.orig	2020-04-19 18:25:17 UTC
+++ test/endpoint/endpoint.cpp
@@ -53,7 +53,7 @@ BOOST_AUTO_TEST_CASE( initialize_server_asio_external 
 
 BOOST_AUTO_TEST_CASE( initialize_server_asio_external ) {
     websocketpp::server<websocketpp::config::asio> s;
-    boost::asio::io_service ios;
+    boost::asio::io_context ios;
     s.init_asio(&ios);
 }
 
@@ -141,8 +141,8 @@ BOOST_AUTO_TEST_CASE( listen_after_listen_failure ) {
     server1.init_asio();
     server2.init_asio();
 
-    boost::asio::ip::tcp::endpoint ep1(boost::asio::ip::address::from_string("127.0.0.1"), 12345);
-    boost::asio::ip::tcp::endpoint ep2(boost::asio::ip::address::from_string("127.0.0.1"), 23456);
+    boost::asio::ip::tcp::endpoint ep1(boost::asio::ip::make_address("127.0.0.1"), 12345);
+    boost::asio::ip::tcp::endpoint ep2(boost::asio::ip::make_address("127.0.0.1"), 23456);
 
     server1.listen(ep1, ec);
     BOOST_CHECK(!ec);
