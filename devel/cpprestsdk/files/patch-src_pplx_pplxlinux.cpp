--- src/pplx/pplxlinux.cpp.orig	2023-12-05 04:23:31 UTC
+++ src/pplx/pplxlinux.cpp
@@ -35,7 +35,7 @@ _PPLXIMP void linux_scheduler::schedule(TaskProc_t pro
 
 _PPLXIMP void linux_scheduler::schedule(TaskProc_t proc, void* param)
 {
-    crossplat::threadpool::shared_instance().service().post(boost::bind(proc, param));
+    boost::asio::post(crossplat::threadpool::shared_instance().service(), boost::bind(proc, param));
 }
 
 } // namespace details
