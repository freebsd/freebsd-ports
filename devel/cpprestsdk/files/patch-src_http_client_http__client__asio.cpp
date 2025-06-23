--- src/http/client/http_client_asio.cpp.orig	2023-12-05 04:23:31 UTC
+++ src/http/client/http_client_asio.cpp
@@ -146,7 +146,7 @@ class asio_connection (public)
     friend class asio_client;
 
 public:
-    asio_connection(boost::asio::io_service& io_service)
+    asio_connection(boost::asio::io_context& io_service)
         : m_socket_lock()
         , m_socket(io_service)
         , m_ssl_stream()
@@ -581,10 +581,8 @@ class asio_context final : public request_context, pub
 
             m_context->m_timer.start();
 
-            tcp::resolver::query query(utility::conversions::to_utf8string(proxy_host), to_string(proxy_port));
-
             auto client = std::static_pointer_cast<asio_client>(m_context->m_http_client);
-            m_context->m_resolver.async_resolve(query,
+            m_context->m_resolver.async_resolve(utility::conversions::to_utf8string(proxy_host), to_string(proxy_port),
                                                 boost::bind(&ssl_proxy_tunnel::handle_resolve,
                                                             shared_from_this(),
                                                             boost::asio::placeholders::error,
@@ -592,8 +590,9 @@ class asio_context final : public request_context, pub
         }
 
     private:
-        void handle_resolve(const boost::system::error_code& ec, tcp::resolver::iterator endpoints)
+        void handle_resolve(const boost::system::error_code& ec, tcp::resolver::results_type results)
         {
+            auto iterator = results.begin();
             if (ec)
             {
                 m_context->report_error("Error resolving proxy address", ec, httpclient_errorcode_context::connect);
@@ -601,16 +600,16 @@ class asio_context final : public request_context, pub
             else
             {
                 m_context->m_timer.reset();
-                auto endpoint = *endpoints;
+                auto endpoint = *iterator;
                 m_context->m_connection->async_connect(endpoint,
                                                        boost::bind(&ssl_proxy_tunnel::handle_tcp_connect,
                                                                    shared_from_this(),
                                                                    boost::asio::placeholders::error,
-                                                                   ++endpoints));
+                                                                   ++iterator, results.end()));
             }
         }
 
-        void handle_tcp_connect(const boost::system::error_code& ec, tcp::resolver::iterator endpoints)
+        void handle_tcp_connect(const boost::system::error_code& ec, tcp::resolver::results_type::iterator endpoints, tcp::resolver::results_type::iterator endpoints_end)
         {
             if (!ec)
             {
@@ -621,7 +620,7 @@ class asio_context final : public request_context, pub
                                                                  shared_from_this(),
                                                                  boost::asio::placeholders::error));
             }
-            else if (endpoints == tcp::resolver::iterator())
+            else if (endpoints == endpoints_end)
             {
                 m_context->report_error(
                     "Failed to connect to any resolved proxy endpoint", ec, httpclient_errorcode_context::connect);
@@ -646,7 +645,7 @@ class asio_context final : public request_context, pub
                                                        boost::bind(&ssl_proxy_tunnel::handle_tcp_connect,
                                                                    shared_from_this(),
                                                                    boost::asio::placeholders::error,
-                                                                   ++endpoints));
+                                                                   ++endpoints, endpoints_end));
             }
         }
 
@@ -885,8 +884,7 @@ class asio_context final : public request_context, pub
                 auto tcp_host = proxy_type == http_proxy_type::http ? proxy_host : host;
                 auto tcp_port = proxy_type == http_proxy_type::http ? proxy_port : port;
 
-                tcp::resolver::query query(tcp_host, to_string(tcp_port));
-                ctx->m_resolver.async_resolve(query,
+                ctx->m_resolver.async_resolve(tcp_host, to_string(tcp_port),
                                               boost::bind(&asio_context::handle_resolve,
                                                           ctx,
                                                           boost::asio::placeholders::error,
@@ -1006,7 +1004,7 @@ class asio_context final : public request_context, pub
         request_context::report_error(errorcodeValue, message);
     }
 
-    void handle_connect(const boost::system::error_code& ec, tcp::resolver::iterator endpoints)
+    void handle_connect(const boost::system::error_code& ec, tcp::resolver::results_type::iterator endpoints, tcp::resolver::results_type::iterator endpoints_end)
     {
         m_timer.reset();
         if (!ec)
@@ -1019,7 +1017,7 @@ class asio_context final : public request_context, pub
         {
             report_error("Request canceled by user.", ec, httpclient_errorcode_context::connect);
         }
-        else if (endpoints == tcp::resolver::iterator())
+        else if (endpoints == endpoints_end)
         {
             report_error("Failed to connect to any resolved endpoint", ec, httpclient_errorcode_context::connect);
         }
@@ -1041,28 +1039,29 @@ class asio_context final : public request_context, pub
             m_connection->async_connect(
                 endpoint,
                 boost::bind(
-                    &asio_context::handle_connect, shared_from_this(), boost::asio::placeholders::error, ++endpoints));
+                    &asio_context::handle_connect, shared_from_this(), boost::asio::placeholders::error, ++endpoints, endpoints_end));
         }
     }
 
-    void handle_resolve(const boost::system::error_code& ec, tcp::resolver::iterator endpoints)
+    void handle_resolve(const boost::system::error_code& ec, tcp::resolver::results_type results)
     {
         if (ec)
         {
             report_error("Error resolving address", ec, httpclient_errorcode_context::connect);
         }
-        else if (endpoints == tcp::resolver::iterator())
+        else if (results.empty())
         {
             report_error("Failed to resolve address", ec, httpclient_errorcode_context::connect);
         }
         else
         {
             m_timer.reset();
-            auto endpoint = *endpoints;
+            auto iterator = results.begin();
+            auto endpoint = *iterator;
             m_connection->async_connect(
                 endpoint,
                 boost::bind(
-                    &asio_context::handle_connect, shared_from_this(), boost::asio::placeholders::error, ++endpoints));
+                    &asio_context::handle_connect, shared_from_this(), boost::asio::placeholders::error, ++iterator, results.end()));
         }
     }
 
@@ -1134,7 +1133,7 @@ class asio_context final : public request_context, pub
         }
 #endif // CPPREST_PLATFORM_ASIO_CERT_VERIFICATION_AVAILABLE
 
-        boost::asio::ssl::rfc2818_verification rfc2818(m_connection->cn_hostname());
+        boost::asio::ssl::host_name_verification rfc2818(m_connection->cn_hostname());
         return rfc2818(preverified, verifyCtx);
     }
 
@@ -1182,8 +1181,8 @@ class asio_context final : public request_context, pub
 
         const auto& chunkSize = m_http_client->client_config().chunksize();
         auto readbuf = _get_readbuffer();
-        uint8_t* buf = boost::asio::buffer_cast<uint8_t*>(
-            m_body_buf.prepare(chunkSize + http::details::chunked_encoding::additional_encoding_space));
+        auto bodyBuf = m_body_buf.prepare(chunkSize + http::details::chunked_encoding::additional_encoding_space);
+        uint8_t* buf = static_cast<uint8_t *>(bodyBuf.data());
         const auto this_request = shared_from_this();
         readbuf.getn(buf + http::details::chunked_encoding::data_offset, chunkSize)
             .then([this_request, buf, chunkSize AND_CAPTURE_MEMBER_FUNCTION_POINTERS](pplx::task<size_t> op) {
@@ -1247,7 +1246,7 @@ class asio_context final : public request_context, pub
         const auto readSize = static_cast<size_t>((std::min)(
             static_cast<uint64_t>(m_http_client->client_config().chunksize()), m_content_length - m_uploaded));
         auto readbuf = _get_readbuffer();
-        readbuf.getn(boost::asio::buffer_cast<uint8_t*>(m_body_buf.prepare(readSize)), readSize)
+        readbuf.getn(static_cast<uint8_t*>(m_body_buf.prepare(readSize).data()), readSize)
             .then([this_request AND_CAPTURE_MEMBER_FUNCTION_POINTERS](pplx::task<size_t> op) {
                 try
                 {
@@ -1639,7 +1638,7 @@ class asio_context final : public request_context, pub
                     std::vector<uint8_t> decompressed;
 
                     bool boo =
-                        decompress(boost::asio::buffer_cast<const uint8_t*>(m_body_buf.data()), to_read, decompressed);
+                        decompress(static_cast<const uint8_t*>(m_body_buf.data().data()), to_read, decompressed);
                     if (!boo)
                     {
                         report_exception(std::runtime_error("Failed to decompress the response body"));
@@ -1687,7 +1686,7 @@ class asio_context final : public request_context, pub
                 }
                 else
                 {
-                    writeBuffer.putn_nocopy(boost::asio::buffer_cast<const uint8_t*>(m_body_buf.data()), to_read)
+                    writeBuffer.putn_nocopy(static_cast<const uint8_t*>(m_body_buf.data().data()), to_read)
                         .then([this_request, to_read AND_CAPTURE_MEMBER_FUNCTION_POINTERS](pplx::task<size_t> op) {
                             try
                             {
@@ -1759,7 +1758,7 @@ class asio_context final : public request_context, pub
                 std::vector<uint8_t> decompressed;
 
                 bool boo =
-                    decompress(boost::asio::buffer_cast<const uint8_t*>(m_body_buf.data()), read_size, decompressed);
+                    decompress(static_cast<const uint8_t*>(m_body_buf.data().data()), read_size, decompressed);
                 if (!boo)
                 {
                     this_request->report_exception(std::runtime_error("Failed to decompress the response body"));
@@ -1821,7 +1820,7 @@ class asio_context final : public request_context, pub
             }
             else
             {
-                writeBuffer.putn_nocopy(boost::asio::buffer_cast<const uint8_t*>(m_body_buf.data()), read_size)
+                writeBuffer.putn_nocopy(static_cast<const uint8_t*>(m_body_buf.data().data()), read_size)
                     .then([this_request AND_CAPTURE_MEMBER_FUNCTION_POINTERS](pplx::task<size_t> op) {
                         size_t writtenSize = 0;
                         try
@@ -1870,7 +1869,7 @@ class asio_context final : public request_context, pub
             assert(!m_ctx.expired());
             m_state = started;
 
-            m_timer.expires_from_now(m_duration);
+            m_timer.expires_after(m_duration);
             auto ctx = m_ctx;
             m_timer.async_wait([ctx AND_CAPTURE_MEMBER_FUNCTION_POINTERS](const boost::system::error_code& ec) {
                 handle_timeout(ec, ctx);
@@ -1881,7 +1880,7 @@ class asio_context final : public request_context, pub
         {
             assert(m_state == started || m_state == timedout);
             assert(!m_ctx.expired());
-            if (m_timer.expires_from_now(m_duration) > 0)
+            if (m_timer.expires_after(m_duration) > 0)
             {
                 // The existing handler was canceled so schedule a new one.
                 assert(m_state == started);
