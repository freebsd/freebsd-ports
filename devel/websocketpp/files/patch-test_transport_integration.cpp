--- test/transport/integration.cpp.orig	2020-04-19 18:25:17 UTC
+++ test/transport/integration.cpp
@@ -221,7 +221,7 @@ void run_dummy_server(int port) {
     using boost::asio::ip::tcp;
 
     try {
-        boost::asio::io_service io_service;
+        boost::asio::io_context io_service;
         tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v6(), port));
         tcp::socket socket(io_service);
 
@@ -248,13 +248,12 @@ void run_dummy_client(std::string port) {
     using boost::asio::ip::tcp;
 
     try {
-        boost::asio::io_service io_service;
+        boost::asio::io_context io_service;
         tcp::resolver resolver(io_service);
-        tcp::resolver::query query("localhost", port);
-        tcp::resolver::iterator iterator = resolver.resolve(query);
+        tcp::resolver::results_type results = resolver.resolve("localhost", port);
         tcp::socket socket(io_service);
 
-        boost::asio::connect(socket, iterator);
+        boost::asio::connect(socket, results);
         for (;;) {
             char data[512];
             boost::system::error_code ec;
@@ -361,7 +360,7 @@ class test_deadline_timer (public)
     : m_timer(m_io_service, boost::posix_time::seconds(seconds))
     {
         m_timer.async_wait(bind(&test_deadline_timer::expired, this, ::_1));
-        std::size_t (boost::asio::io_service::*run)() = &boost::asio::io_service::run;
+        std::size_t (boost::asio::io_context::*run)() = &boost::asio::io_context::run;
         m_timer_thread = websocketpp::lib::thread(websocketpp::lib::bind(run, &m_io_service));
     }
     ~test_deadline_timer()
@@ -379,7 +378,7 @@ class test_deadline_timer (public)
         BOOST_FAIL("Test timed out");
     }
 
-    boost::asio::io_service m_io_service;
+    boost::asio::io_context m_io_service;
     boost::asio::deadline_timer m_timer;
     websocketpp::lib::thread m_timer_thread;
 };
