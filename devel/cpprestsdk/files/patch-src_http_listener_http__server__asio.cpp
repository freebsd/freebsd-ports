--- src/http/listener/http_server_asio.cpp.orig	2023-12-05 04:23:31 UTC
+++ src/http/listener/http_server_asio.cpp
@@ -520,17 +520,14 @@ void hostport_listener::start()
     auto& service = crossplat::threadpool::shared_instance().service();
     tcp::resolver resolver(service);
     // #446: boost resolver does not recognize "+" as a host wildchar
-    tcp::resolver::query query =
-        ("+" == m_host) ? tcp::resolver::query(m_port, boost::asio::ip::resolver_query_base::flags())
-                        : tcp::resolver::query(m_host, m_port, boost::asio::ip::resolver_query_base::flags());
 
-    tcp::endpoint endpoint = *resolver.resolve(query);
+    tcp::endpoint endpoint = (("+" == m_host) ? *(resolver.resolve("", m_port).begin()) : *(resolver.resolve(m_host, m_port).begin()));
 
     m_acceptor.reset(new tcp::acceptor(service));
     m_acceptor->open(endpoint.protocol());
     m_acceptor->set_option(socket_base::reuse_address(true));
     m_acceptor->bind(endpoint);
-    m_acceptor->listen(0 != m_backlog ? m_backlog : socket_base::max_connections);
+    m_acceptor->listen(0 != m_backlog ? m_backlog : socket_base::max_listen_connections);
 
     auto socket = new ip::tcp::socket(service);
     std::unique_ptr<ip::tcp::socket> usocket(socket);
@@ -881,7 +878,7 @@ will_deref_t asio_server_connection::handle_chunked_bo
     else
     {
         auto writebuf = requestImpl->outstream().streambuf();
-        writebuf.putn_nocopy(buffer_cast<const uint8_t*>(m_request_buf.data()), toWrite)
+        writebuf.putn_nocopy(static_cast<const uint8_t*>(m_request_buf.data().data()), toWrite)
             .then([=](pplx::task<size_t> writeChunkTask) -> will_deref_t {
                 try
                 {
@@ -913,7 +910,7 @@ will_deref_t asio_server_connection::handle_body(const
     {
         auto writebuf = requestImpl->outstream().streambuf();
         writebuf
-            .putn_nocopy(boost::asio::buffer_cast<const uint8_t*>(m_request_buf.data()),
+            .putn_nocopy(static_cast<const uint8_t*>(m_request_buf.data().data()),
                          (std::min)(m_request_buf.size(), m_read_size - m_read))
             .then([this](pplx::task<size_t> writtenSizeTask) -> will_deref_t {
                 size_t writtenSize = 0;
@@ -1134,7 +1131,7 @@ will_deref_and_erase_t asio_server_connection::handle_
     }
     auto membuf = m_response_buf.prepare(ChunkSize + chunked_encoding::additional_encoding_space);
 
-    readbuf.getn(buffer_cast<uint8_t*>(membuf) + chunked_encoding::data_offset, ChunkSize)
+    readbuf.getn(static_cast<uint8_t*>(membuf.data()) + chunked_encoding::data_offset, ChunkSize)
         .then([=](pplx::task<size_t> actualSizeTask) -> will_deref_and_erase_t {
             size_t actualSize = 0;
             try
@@ -1146,7 +1143,7 @@ will_deref_and_erase_t asio_server_connection::handle_
                 return cancel_sending_response_with_error(response, std::current_exception());
             }
             size_t offset = chunked_encoding::add_chunked_delimiters(
-                buffer_cast<uint8_t*>(membuf), ChunkSize + chunked_encoding::additional_encoding_space, actualSize);
+                static_cast<uint8_t*>(membuf.data()), ChunkSize + chunked_encoding::additional_encoding_space, actualSize);
             m_response_buf.commit(actualSize + chunked_encoding::additional_encoding_space);
             m_response_buf.consume(offset);
             if (actualSize == 0)
@@ -1167,7 +1164,7 @@ will_deref_and_erase_t asio_server_connection::handle_
         return cancel_sending_response_with_error(
             response, std::make_exception_ptr(http_exception("Response stream close early!")));
     size_t readBytes = (std::min)(ChunkSize, m_write_size - m_write);
-    readbuf.getn(buffer_cast<uint8_t*>(m_response_buf.prepare(readBytes)), readBytes)
+    readbuf.getn(static_cast<uint8_t*>(m_response_buf.prepare(readBytes).data()), readBytes)
         .then([=](pplx::task<size_t> actualSizeTask) -> will_deref_and_erase_t {
             size_t actualSize = 0;
             try
