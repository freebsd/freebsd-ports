https://github.com/boostorg/thread/issues/402

In file included from src/third_party/boost/libs/thread/src/pthread/thread.cpp:19:
src/third_party/boost/boost/thread/future.hpp:4672:19: error: no member named 'that' in 'run_it<FutureExecutorContinuationSharedState>'; did you mean 'that_'?
 4672 |           that_=x.that;
      |                   ^~~~

--- src/third_party/boost/boost/thread/future.hpp.orig	2024-12-12 08:36:29 UTC
+++ src/third_party/boost/boost/thread/future.hpp
@@ -4669,7 +4669,7 @@ namespace detail
       }
       run_it& operator=(BOOST_THREAD_RV_REF(run_it) x) BOOST_NOEXCEPT {
         if (this != &x) {
-          that_=x.that;
+          that_=x.that_;
           x.that_.reset();
         }
         return *this;
