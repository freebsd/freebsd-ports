--- tests/functional/pplx/pplx_test/pplx_op_test.cpp.orig	2023-12-05 04:23:31 UTC
+++ tests/functional/pplx/pplx_test/pplx_op_test.cpp
@@ -57,7 +57,7 @@ class pplx_dflt_scheduler : public pplx::scheduler_int
     virtual void schedule(pplx::TaskProc_t proc, void* param)
     {
         pplx::details::atomic_increment(s_flag);
-        m_pool->service().post([=]() -> void { proc(param); });
+        boost::asio::post(m_pool->service(), [=]() -> void { proc(param); });
     }
 
 public:
