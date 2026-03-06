--- src/slic3r/GUI/HttpServer.hpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/HttpServer.hpp
@@ -115,7 +115,7 @@ class HttpServer (private)
     {
     public:
         HttpServer&                        server;
-        boost::asio::io_service            io_service;
+        boost::asio::io_context            io_service;
         boost::asio::ip::tcp::acceptor     acceptor;
         std::set<std::shared_ptr<session>> sessions;
 
