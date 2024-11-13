--- base/threading/platform_thread.h.orig	2024-06-18 21:43:18 UTC
+++ base/threading/platform_thread.h
@@ -49,6 +49,8 @@ typedef mach_port_t PlatformThreadId;
 typedef zx_koid_t PlatformThreadId;
 #elif BUILDFLAG(IS_APPLE)
 typedef mach_port_t PlatformThreadId;
+#elif BUILDFLAG(IS_BSD)
+typedef uint64_t PlatformThreadId;
 #elif BUILDFLAG(IS_POSIX)
 typedef pid_t PlatformThreadId;
 #endif
