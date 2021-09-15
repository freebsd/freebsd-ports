Note that this patch may be removed after FreeBSD 11.x EoL
as latest FreeBSD versions have proper
pthread_setname_np/pthread_getname_np support.

--- src/libslic3r/Thread.cpp.orig	2021-07-16 10:14:03 UTC
+++ src/libslic3r/Thread.cpp
@@ -9,10 +9,10 @@
 #include <atomic>
 #include <condition_variable>
 #include <mutex>
+#include <thread>
+#include <tbb/global_control.h>
 #include <tbb/parallel_for.h>
-#include <tbb/tbb_thread.h>
 #include <tbb/task_arena.h>
-#include <tbb/task_scheduler_init.h>
 
 #include "Thread.hpp"
 
@@ -206,13 +206,13 @@ void name_tbb_thread_pool_threads()
 	nthreads = 1;
 #endif
 
-	if (nthreads != nthreads_hw) 
-		new tbb::task_scheduler_init(int(nthreads));
+	if (nthreads != nthreads_hw)
+		tbb::global_control(tbb::global_control::max_allowed_parallelism, nthreads);
 
 	std::atomic<size_t>		nthreads_running(0);
 	std::condition_variable cv;
 	std::mutex				cv_m;
-	auto					master_thread_id = tbb::this_tbb_thread::get_id();
+	auto					master_thread_id = std::this_thread::get_id();
     tbb::parallel_for(
         tbb::blocked_range<size_t>(0, nthreads, 1),
         [&nthreads_running, nthreads, &master_thread_id, &cv, &cv_m](const tbb::blocked_range<size_t> &range) {
@@ -226,7 +226,7 @@ void name_tbb_thread_pool_threads()
 				std::unique_lock<std::mutex> lk(cv_m);
 			    cv.wait(lk, [&nthreads_running, nthreads]{return nthreads_running == nthreads;});
         	}
-        	auto thread_id = tbb::this_tbb_thread::get_id();
+        	auto thread_id = std::this_thread::get_id();
 			if (thread_id == master_thread_id) {
 				// The calling thread runs the 0'th task.
 				assert(range.begin() == 0);
