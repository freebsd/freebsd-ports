Fix unsafe_wait visibility

Fixes tests 66 and 74:

66 - test_global_control (Subprocess aborted)
74 - test_tbb_header (Failed)

--- include/oneapi/tbb/detail/_exception.h.orig	2025-10-29 11:31:36 UTC
+++ include/oneapi/tbb/detail/_exception.h
@@ -66,14 +66,14 @@ class TBB_EXPORT missing_wait : public std::exception 
 };
 
 //! Exception for impossible finalization of task_sheduler_handle
-#if __APPLE__
+#if __APPLE__ || __FreeBSD__
     #pragma GCC visibility push(default)
 #endif
 class TBB_EXPORT unsafe_wait : public std::runtime_error {
 public:
     unsafe_wait(const char* msg) : std::runtime_error(msg) {}
 };
-#if __APPLE__
+#if __APPLE__ || __FreeBSD__
     #pragma GCC visibility pop
 #endif
 
