--- websocketpp/transport/asio/endpoint.hpp.orig	2020-04-19 18:25:17 UTC
+++ websocketpp/transport/asio/endpoint.hpp
@@ -78,7 +78,7 @@ class endpoint : public config::socket_type { (public)
     typedef typename transport_con_type::ptr transport_con_ptr;
 
     /// Type of a pointer to the ASIO io_service being used
-    typedef lib::asio::io_service * io_service_ptr;
+    typedef lib::asio::io_context * io_context_ptr;
     /// Type of a shared pointer to the acceptor being used
     typedef lib::shared_ptr<lib::asio::ip::tcp::acceptor> acceptor_ptr;
     /// Type of a shared pointer to the resolver being used
@@ -86,7 +86,7 @@ class endpoint : public config::socket_type { (public)
     /// Type of timer handle
     typedef lib::shared_ptr<lib::asio::steady_timer> timer_ptr;
     /// Type of a shared pointer to an io_service work object
-    typedef lib::shared_ptr<lib::asio::io_service::work> work_ptr;
+    typedef lib::shared_ptr<lib::asio::executor_work_guard<lib::asio::io_context::executor_type>> work_ptr;
 
     /// Type of socket pre-bind handler
     typedef lib::function<lib::error_code(acceptor_ptr)> tcp_pre_bind_handler;
@@ -95,7 +95,7 @@ class endpoint : public config::socket_type { (public)
     explicit endpoint()
       : m_io_service(NULL)
       , m_external_io_service(false)
-      , m_listen_backlog(lib::asio::socket_base::max_connections)
+      , m_listen_backlog(lib::asio::socket_base::max_listen_connections)
       , m_reuse_addr(false)
       , m_state(UNINITIALIZED)
     {
@@ -135,7 +135,7 @@ class endpoint : public config::socket_type { (public)
       , m_io_service(src.m_io_service)
       , m_external_io_service(src.m_external_io_service)
       , m_acceptor(src.m_acceptor)
-      , m_listen_backlog(lib::asio::socket_base::max_connections)
+      , m_listen_backlog(lib::asio::socket_base::max_listen_connections)
       , m_reuse_addr(src.m_reuse_addr)
       , m_elog(src.m_elog)
       , m_alog(src.m_alog)
@@ -182,7 +182,7 @@ class endpoint : public config::socket_type { (public)
      * @param ptr A pointer to the io_service to use for asio events
      * @param ec Set to indicate what error occurred, if any.
      */
-    void init_asio(io_service_ptr ptr, lib::error_code & ec) {
+    void init_asio(io_context_ptr ptr, lib::error_code & ec) {
         if (m_state != UNINITIALIZED) {
             m_elog->write(log::elevel::library,
                 "asio::init_asio called from the wrong state");
@@ -209,7 +209,7 @@ class endpoint : public config::socket_type { (public)
      *
      * @param ptr A pointer to the io_service to use for asio events
      */
-    void init_asio(io_service_ptr ptr) {
+    void init_asio(io_context_ptr ptr) {
         lib::error_code ec;
         init_asio(ptr,ec);
         if (ec) { throw exception(ec); }
@@ -230,9 +230,9 @@ class endpoint : public config::socket_type { (public)
         // TODO: remove the use of auto_ptr when C++98/03 support is no longer
         //       necessary.
 #ifdef _WEBSOCKETPP_CPP11_MEMORY_
-        lib::unique_ptr<lib::asio::io_service> service(new lib::asio::io_service());
+        lib::unique_ptr<lib::asio::io_context> service(new lib::asio::io_context());
 #else
-        lib::auto_ptr<lib::asio::io_service> service(new lib::asio::io_service());
+        lib::auto_ptr<lib::asio::io_context> service(new lib::asio::io_context());
 #endif
         init_asio(service.get(), ec);
         if( !ec ) service.release(); // Call was successful, transfer ownership
@@ -252,9 +252,9 @@ class endpoint : public config::socket_type { (public)
         // TODO: remove the use of auto_ptr when C++98/03 support is no longer
         //       necessary.
 #ifdef _WEBSOCKETPP_CPP11_MEMORY_
-        lib::unique_ptr<lib::asio::io_service> service(new lib::asio::io_service());
+        lib::unique_ptr<lib::asio::io_context> service(new lib::asio::io_context());
 #else
-        lib::auto_ptr<lib::asio::io_service> service(new lib::asio::io_service());
+        lib::auto_ptr<lib::asio::io_context> service(new lib::asio::io_context());
 #endif
         init_asio( service.get() );
         // If control got this far without an exception, then ownership has successfully been taken
@@ -375,7 +375,7 @@ class endpoint : public config::socket_type { (public)
      *
      * @return A reference to the endpoint's io_service
      */
-    lib::asio::io_service & get_io_service() {
+    lib::asio::io_context & get_io_service() {
         return *m_io_service;
     }
     
@@ -558,9 +558,9 @@ class endpoint : public config::socket_type { (public)
     {
         using lib::asio::ip::tcp;
         tcp::resolver r(*m_io_service);
-        tcp::resolver::query query(host, service);
-        tcp::resolver::iterator endpoint_iterator = r.resolve(query);
-        tcp::resolver::iterator end;
+        tcp::resolver::results_type endpoints = r.resolve(host, service);
+        auto endpoint_iterator = endpoints.begin();
+        auto end = endpoints.end();
         if (endpoint_iterator == end) {
             m_elog->write(log::elevel::library,
                 "asio::listen could not resolve the supplied host or service");
@@ -666,7 +666,7 @@ class endpoint : public config::socket_type { (public)
 
     /// wraps the reset method of the internal io_service object
     void reset() {
-        m_io_service->reset();
+        m_io_service->restart();
     }
 
     /// wraps the stopped method of the internal io_service object
@@ -687,7 +687,7 @@ class endpoint : public config::socket_type { (public)
      * @since 0.3.0
      */
     void start_perpetual() {
-        m_work.reset(new lib::asio::io_service::work(*m_io_service));
+        m_work.reset(new lib::asio::executor_work_guard<lib::asio::io_context::executor_type>(lib::asio::make_work_guard(*m_io_service)));
     }
 
     /// Clears the endpoint's perpetual flag, allowing it to exit when empty
@@ -883,8 +883,6 @@ class endpoint : public config::socket_type { (public)
             port = pu->get_port_str();
         }
 
-        tcp::resolver::query query(host,port);
-
         if (m_alog->static_test(log::alevel::devel)) {
             m_alog->write(log::alevel::devel,
                 "starting async DNS resolve for "+host+":"+port);
@@ -905,7 +903,7 @@ class endpoint : public config::socket_type { (public)
 
         if (config::enable_multithreading) {
             m_resolver->async_resolve(
-                query,
+                host, port,
                 tcon->get_strand()->wrap(lib::bind(
                     &type::handle_resolve,
                     this,
@@ -918,7 +916,7 @@ class endpoint : public config::socket_type { (public)
             );
         } else {
             m_resolver->async_resolve(
-                query,
+                host, port,
                 lib::bind(
                     &type::handle_resolve,
                     this,
@@ -966,10 +964,10 @@ class endpoint : public config::socket_type { (public)
 
     void handle_resolve(transport_con_ptr tcon, timer_ptr dns_timer,
         connect_handler callback, lib::asio::error_code const & ec,
-        lib::asio::ip::tcp::resolver::iterator iterator)
+        lib::asio::ip::tcp::resolver::results_type results)
     {
         if (ec == lib::asio::error::operation_aborted ||
-            lib::asio::is_neg(dns_timer->expires_from_now()))
+            lib::asio::is_neg(dns_timer->expiry() - std::chrono::steady_clock::now()))
         {
             m_alog->write(log::alevel::devel,"async_resolve cancelled");
             return;
@@ -987,8 +985,8 @@ class endpoint : public config::socket_type { (public)
             std::stringstream s;
             s << "Async DNS resolve successful. Results: ";
 
-            lib::asio::ip::tcp::resolver::iterator it, end;
-            for (it = iterator; it != end; ++it) {
+            lib::asio::ip::tcp::resolver::results_type::iterator it, end;
+            for (it = results.begin(); it != results.end(); ++it) {
                 s << (*it).endpoint() << " ";
             }
 
@@ -1014,7 +1012,7 @@ class endpoint : public config::socket_type { (public)
         if (config::enable_multithreading) {
             lib::asio::async_connect(
                 tcon->get_raw_socket(),
-                iterator,
+                results,
                 tcon->get_strand()->wrap(lib::bind(
                     &type::handle_connect,
                     this,
@@ -1027,7 +1025,7 @@ class endpoint : public config::socket_type { (public)
         } else {
             lib::asio::async_connect(
                 tcon->get_raw_socket(),
-                iterator,
+                results,
                 lib::bind(
                     &type::handle_connect,
                     this,
@@ -1077,7 +1075,7 @@ class endpoint : public config::socket_type { (public)
         connect_handler callback, lib::asio::error_code const & ec)
     {
         if (ec == lib::asio::error::operation_aborted ||
-            lib::asio::is_neg(con_timer->expires_from_now()))
+            lib::asio::is_neg(con_timer->expiry() - std::chrono::steady_clock::now()))
         {
             m_alog->write(log::alevel::devel,"async_connect cancelled");
             return;
@@ -1158,7 +1156,7 @@ class endpoint : public config::socket_type { (public)
     tcp_init_handler    m_tcp_post_init_handler;
 
     // Network Resources
-    io_service_ptr      m_io_service;
+    io_context_ptr      m_io_service;
     bool                m_external_io_service;
     acceptor_ptr        m_acceptor;
     resolver_ptr        m_resolver;
