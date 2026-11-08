-- Define FOLLY_SYS_gettid for FreeBSD using SYS_thr_self.
-- FreeBSD does not define SYS_gettid; the fallthrough __NR_gettid is Linux-only
-- and causes compilation failures even in discarded if-constexpr branches.
--- folly/portability/SysSyscall.h.orig	2026-10-05 14:18:47 UTC
+++ folly/portability/SysSyscall.h
@@ -38,6 +38,8 @@
 // linux_syscall() path below returns -1 on Emscripten without invoking it,
 // so the sentinel value is inert at runtime.
 #define FOLLY_SYS_gettid 0
+#elif defined(__FreeBSD__)
+#define FOLLY_SYS_gettid SYS_thr_self
 #elif defined(SYS_gettid)
 #define FOLLY_SYS_gettid SYS_gettid
 #else
