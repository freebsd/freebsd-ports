--- include/pplx/threadpool.h.orig	2023-12-05 04:23:31 UTC
+++ include/pplx/threadpool.h
@@ -69,15 +69,15 @@ class threadpool (public)
     CASABLANCA_DEPRECATED("Use `.service().post(task)` directly.")
     void schedule(T task)
     {
-        service().post(task);
+        boost::asio::post(service(), task);
     }
 
-    boost::asio::io_service& service() { return m_service; }
+    boost::asio::io_context& service() { return m_service; }
 
 protected:
     threadpool(size_t num_threads) : m_service(static_cast<int>(num_threads)) {}
 
-    boost::asio::io_service m_service;
+    boost::asio::io_context m_service;
 };
 
 } // namespace crossplat
