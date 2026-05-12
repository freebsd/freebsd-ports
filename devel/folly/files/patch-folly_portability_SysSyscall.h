-- Define FOLLY_SYS_gettid for FreeBSD using SYS_thr_self.
-- FreeBSD does not define SYS_gettid; the fallthrough __NR_gettid is Linux-only
-- and causes compilation failures even in discarded if-constexpr branches.
--- folly/portability/SysSyscall.h.orig	2026-05-12 19:34:09 UTC
+++ folly/portability/SysSyscall.h
@@ -31,6 +31,8 @@
 #define FOLLY_SYS_gettid SYS_thread_selfid
 #elif defined(__EMSCRIPTEN__)
 #define FOLLY_SYS_gettid 0
+#elif defined(__FreeBSD__)
+#define FOLLY_SYS_gettid SYS_thr_self
 #elif defined(SYS_gettid)
 #define FOLLY_SYS_gettid SYS_gettid
 #else
