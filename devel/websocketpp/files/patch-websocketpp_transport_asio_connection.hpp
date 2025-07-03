--- websocketpp/transport/asio/connection.hpp.orig	2020-04-19 18:25:17 UTC
+++ websocketpp/transport/asio/connection.hpp
@@ -86,9 +86,9 @@ class connection : public config::socket_type::socket_
     typedef typename response_type::ptr response_ptr;
 
     /// Type of a pointer to the Asio io_service being used
-    typedef lib::asio::io_service * io_service_ptr;
+    typedef lib::asio::io_context * io_context_ptr;
     /// Type of a pointer to the Asio io_service::strand being used
-    typedef lib::shared_ptr<lib::asio::io_service::strand> strand_ptr;
+    typedef lib::shared_ptr<lib::asio::io_context::strand> strand_ptr;
     /// Type of a pointer to the Asio timer class
     typedef lib::shared_ptr<lib::asio::steady_timer> timer_ptr;
 
@@ -458,11 +458,11 @@ class connection : public config::socket_type::socket_
      *
      * @return Status code for the success or failure of the initialization
      */
-    lib::error_code init_asio (io_service_ptr io_service) {
+    lib::error_code init_asio (io_context_ptr io_service) {
         m_io_service = io_service;
 
         if (config::enable_multithreading) {
-            m_strand.reset(new lib::asio::io_service::strand(*io_service));
+            m_strand.reset(new lib::asio::io_context::strand(*io_service));
         }
 
         lib::error_code ec = socket_con_type::init_asio(io_service, m_strand,
@@ -573,7 +573,7 @@ class connection : public config::socket_type::socket_
         lib::error_code const & ec)
     {
         if (ec == transport::error::operation_aborted ||
-            (post_timer && lib::asio::is_neg(post_timer->expires_from_now())))
+            (post_timer && lib::asio::is_neg(post_timer->expiry() - std::chrono::steady_clock::now())))
         {
             m_alog->write(log::alevel::devel,"post_init cancelled");
             return;
@@ -679,7 +679,7 @@ class connection : public config::socket_type::socket_
         // Whatever aborted it will be issuing the callback so we are safe to
         // return
         if (ec == lib::asio::error::operation_aborted ||
-            lib::asio::is_neg(m_proxy_data->timer->expires_from_now()))
+            lib::asio::is_neg(m_proxy_data->timer->expiry() - std::chrono::steady_clock::now()))
         {
             m_elog->write(log::elevel::devel,"write operation aborted");
             return;
@@ -751,7 +751,7 @@ class connection : public config::socket_type::socket_
         // Whatever aborted it will be issuing the callback so we are safe to
         // return
         if (ec == lib::asio::error::operation_aborted ||
-            lib::asio::is_neg(m_proxy_data->timer->expires_from_now()))
+            lib::asio::is_neg(m_proxy_data->timer->expiry() - std::chrono::steady_clock::now()))
         {
             m_elog->write(log::elevel::devel,"read operation aborted");
             return;
@@ -1012,18 +1012,18 @@ class connection : public config::socket_type::socket_
      */
     lib::error_code interrupt(interrupt_handler handler) {
         if (config::enable_multithreading) {
-            m_io_service->post(m_strand->wrap(handler));
+            lib::asio::post(*m_io_service, m_strand->wrap(handler));
         } else {
-            m_io_service->post(handler);
+            lib::asio::post(*m_io_service, handler);
         }
         return lib::error_code();
     }
 
     lib::error_code dispatch(dispatch_handler handler) {
         if (config::enable_multithreading) {
-            m_io_service->post(m_strand->wrap(handler));
+            lib::asio::post(*m_io_service, m_strand->wrap(handler));
         } else {
-            m_io_service->post(handler);
+            lib::asio::post(*m_io_service, handler);
         }
         return lib::error_code();
     }
@@ -1095,7 +1095,7 @@ class connection : public config::socket_type::socket_
         callback, lib::asio::error_code const & ec)
     {
         if (ec == lib::asio::error::operation_aborted ||
-            lib::asio::is_neg(shutdown_timer->expires_from_now()))
+            lib::asio::is_neg(shutdown_timer->expiry() - std::chrono::steady_clock::now()))
         {
             m_alog->write(log::alevel::devel,"async_shutdown cancelled");
             return;
@@ -1172,7 +1172,7 @@ class connection : public config::socket_type::socket_
     lib::shared_ptr<proxy_data> m_proxy_data;
 
     // transport resources
-    io_service_ptr  m_io_service;
+    io_context_ptr  m_io_service;
     strand_ptr      m_strand;
     connection_hdl  m_connection_hdl;
 
