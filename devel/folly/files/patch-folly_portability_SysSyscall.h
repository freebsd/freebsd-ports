--- folly/portability/SysSyscall.h.orig	2019-06-16 07:32:11 UTC
+++ folly/portability/SysSyscall.h
@@ -21,6 +21,8 @@
 
 #if defined(__APPLE__)
 #define FOLLY_SYS_gettid SYS_thread_selfid
+#elif defined(__FreeBSD__)
+#define FOLLY_SYS_gettid SYS_thr_self
 #elif defined(SYS_gettid)
 #define FOLLY_SYS_gettid SYS_gettid
 #else
