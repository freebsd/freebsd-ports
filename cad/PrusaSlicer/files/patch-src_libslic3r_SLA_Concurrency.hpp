--- src/libslic3r/SLA/Concurrency.hpp.orig	2021-08-14 22:14:14 UTC
+++ src/libslic3r/SLA/Concurrency.hpp
@@ -2,7 +2,7 @@
 #define SLA_CONCURRENCY_H
 
 #include <tbb/spin_mutex.h>
-#include <tbb/mutex.h>
+#include <mutex>
 #include <tbb/parallel_for.h>
 #include <tbb/parallel_reduce.h>
 
@@ -23,7 +23,7 @@ template<bool> struct _ccr {};
 template<> struct _ccr<true>
 {
     using SpinningMutex = tbb::spin_mutex;
-    using BlockingMutex = tbb::mutex;
+    using BlockingMutex = std::mutex;
 
     template<class Fn, class It>
     static IteratorOnly<It, void> loop_(const tbb::blocked_range<It> &range, Fn &&fn)
