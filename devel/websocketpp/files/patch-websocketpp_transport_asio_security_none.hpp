--- websocketpp/transport/asio/security/none.hpp.orig	2020-04-19 18:25:17 UTC
+++ websocketpp/transport/asio/security/none.hpp
@@ -63,9 +63,9 @@ class connection : public lib::enable_shared_from_this
     typedef lib::shared_ptr<type> ptr;
 
     /// Type of a pointer to the Asio io_service being used
-    typedef lib::asio::io_service* io_service_ptr;
+    typedef lib::asio::io_context* io_context_ptr;
     /// Type of a pointer to the Asio io_service strand being used
-    typedef lib::shared_ptr<lib::asio::io_service::strand> strand_ptr;
+    typedef lib::shared_ptr<lib::asio::io_context::strand> strand_ptr;
     /// Type of the ASIO socket being used
     typedef lib::asio::ip::tcp::socket socket_type;
     /// Type of a shared pointer to the socket being used.
@@ -162,7 +162,7 @@ class connection : public lib::enable_shared_from_this
      * @param strand A shared pointer to the connection's asio strand
      * @param is_server Whether or not the endpoint is a server or not.
      */
-    lib::error_code init_asio (io_service_ptr service, strand_ptr, bool)
+    lib::error_code init_asio (io_context_ptr service, strand_ptr, bool)
     {
         if (m_state != UNINITIALIZED) {
             return socket::make_error_code(socket::error::invalid_state);
