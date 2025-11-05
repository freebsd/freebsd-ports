--- folly/debugging/symbolizer/SignalHandler.cpp.orig	2025-11-05 08:46:58 UTC
+++ folly/debugging/symbolizer/SignalHandler.cpp
@@ -159,7 +159,12 @@ bool try_async_reraise(int signum, siginfo_t* info) {
     if (errno != EBADF) { // EBADF here means PIDFD_SELF is not yet supported
       return false;
     }
+#if defined(__linux__)
     auto const tid = linux_syscall(FOLLY_SYS_gettid);
+#elif defined(__FreeBSD__)
+    long tid = 0;
+    syscall(432, &tid);
+#endif
     // pidfd_open introduced in linux-5.3 (released 2019-09-15)
     int const fd = to_narrow(linux_syscall(nr_pidfd_open, tid, 0));
     if (-1 == fd) {
