--- src/pplx/threadpool.cpp.orig	2023-12-05 04:23:31 UTC
+++ src/pplx/threadpool.cpp
@@ -37,7 +37,7 @@ struct threadpool_impl final : crossplat::threadpool
 
 struct threadpool_impl final : crossplat::threadpool
 {
-    threadpool_impl(size_t n) : crossplat::threadpool(n), m_work(m_service)
+    threadpool_impl(size_t n) : crossplat::threadpool(n), m_work(boost::asio::make_work_guard(m_service))
     {
         for (size_t i = 0; i < n; i++)
             add_thread();
@@ -84,7 +84,7 @@ struct threadpool_impl final : crossplat::threadpool
     }
 
     std::vector<std::unique_ptr<boost::asio::detail::thread>> m_threads;
-    boost::asio::io_service::work m_work;
+    boost::asio::executor_work_guard<boost::asio::io_context::executor_type > m_work;
 };
 
 #if defined(_WIN32)
