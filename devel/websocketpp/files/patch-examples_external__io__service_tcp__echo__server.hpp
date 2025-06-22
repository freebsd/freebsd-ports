--- examples/external_io_service/tcp_echo_server.hpp.orig	2020-04-19 18:25:17 UTC
+++ examples/external_io_service/tcp_echo_server.hpp
@@ -44,7 +44,7 @@ struct tcp_echo_session : websocketpp::lib::enable_sha
 struct tcp_echo_session : websocketpp::lib::enable_shared_from_this<tcp_echo_session> {
     typedef websocketpp::lib::shared_ptr<tcp_echo_session> ptr;
     
-    tcp_echo_session(asio::io_service & service) : m_socket(service) {}
+    tcp_echo_session(asio::io_context & service) : m_socket(service) {}
 
     void start() {
         m_socket.async_read_some(asio::buffer(m_buffer, sizeof(m_buffer)),
@@ -72,7 +72,7 @@ struct tcp_echo_server {
 };
 
 struct tcp_echo_server {
-    tcp_echo_server(asio::io_service & service, short port)
+    tcp_echo_server(asio::io_context & service, short port)
         : m_service(service)
         , m_acceptor(service, asio::ip::tcp::endpoint(asio::ip::tcp::v6(), port))
     {
@@ -92,6 +92,6 @@ struct tcp_echo_server {
         start_accept();
     }
 
-    asio::io_service & m_service;
+    asio::io_context & m_service;
     asio::ip::tcp::acceptor m_acceptor;
 };
