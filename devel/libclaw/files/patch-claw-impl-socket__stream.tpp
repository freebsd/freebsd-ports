--- claw/impl/socket_stream.tpp.orig	2013-07-03 23:34:38.000000000 +0400
+++ claw/impl/socket_stream.tpp	2013-09-14 03:12:49.742226665 +0400
@@ -37,7 +37,7 @@
 template<typename CharT, typename Traits>
 claw::net::basic_socket_stream<CharT, Traits>::basic_socket_stream
 ( int read_delay )
-  : m_buffer(read_delay)
+  : std::basic_iostream<CharT, Traits>(&m_buffer), m_buffer(read_delay)
 {
   this->init(&m_buffer);
 } // basic_socket_stream::basic_socket_stream()
@@ -53,7 +53,7 @@
 template<typename CharT, typename Traits>
 claw::net::basic_socket_stream<CharT, Traits>::basic_socket_stream
 ( const char* address, int port, int read_delay )
-  : m_buffer(read_delay)
+  : std::basic_iostream<CharT, Traits>(&m_buffer), m_buffer(read_delay)
 {
   this->init(&m_buffer);
   open(address, port);
