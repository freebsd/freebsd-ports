--- websocketpp/transport/asio/security/tls.hpp.orig	2020-04-19 18:25:17 UTC
+++ websocketpp/transport/asio/security/tls.hpp
@@ -72,9 +72,9 @@ class connection : public lib::enable_shared_from_this
     /// Type of a shared pointer to the ASIO socket being used
     typedef lib::shared_ptr<socket_type> socket_ptr;
     /// Type of a pointer to the ASIO io_service being used
-    typedef lib::asio::io_service * io_service_ptr;
+    typedef lib::asio::io_context * io_context_ptr;
     /// Type of a pointer to the ASIO io_service strand being used
-    typedef lib::shared_ptr<lib::asio::io_service::strand> strand_ptr;
+    typedef lib::shared_ptr<lib::asio::io_context::strand> strand_ptr;
     /// Type of a shared pointer to the ASIO TLS context being used
     typedef lib::shared_ptr<lib::asio::ssl::context> context_ptr;
 
@@ -182,7 +182,7 @@ class connection : public lib::enable_shared_from_this
      * @param strand A pointer to the connection's strand
      * @param is_server Whether or not the endpoint is a server or not.
      */
-    lib::error_code init_asio (io_service_ptr service, strand_ptr strand,
+    lib::error_code init_asio (io_context_ptr service, strand_ptr strand,
         bool is_server)
     {
         if (!m_tls_init_handler) {
@@ -381,7 +381,7 @@ class connection : public lib::enable_shared_from_this
         }
     }
 
-    io_service_ptr      m_io_service;
+    io_context_ptr      m_io_service;
     strand_ptr          m_strand;
     context_ptr         m_context;
     socket_ptr          m_socket;
