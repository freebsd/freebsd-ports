--- src/slic3r/GUI/HttpServer.hpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/HttpServer.hpp
@@ -128,7 +128,7 @@ class HttpServer (private)
     {
     public:
         HttpServer&                        server;
-        boost::asio::io_service            io_service;
+        boost::asio::io_context            io_service;
         boost::asio::ip::tcp::acceptor     acceptor;
         std::set<std::shared_ptr<session>> sessions;
 
