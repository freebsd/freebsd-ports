--- include/quickcpplib/signal_guard.hpp.orig	2023-06-30 03:41:25 UTC
+++ include/quickcpplib/signal_guard.hpp
@@ -531,7 +531,7 @@ namespace signal_guard
 #ifdef _WIN32
       void *_threadh{nullptr};
 #else
-      void *_timerid{nullptr};
+      timer_t _timerid{nullptr};
 #endif
       signal_guard_watchdog_impl *_prev{nullptr}, *_next{nullptr};
       uint64_t _deadline_ms{0};
