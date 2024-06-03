--- base/threading/platform_thread.h.orig	2024-04-15 20:33:42 UTC
+++ base/threading/platform_thread.h
@@ -46,6 +46,8 @@ typedef mach_port_t PlatformThreadId;
 typedef zx_koid_t PlatformThreadId;
 #elif BUILDFLAG(IS_APPLE)
 typedef mach_port_t PlatformThreadId;
+#elif BUILDFLAG(IS_BSD)
+typedef uint64_t PlatformThreadId;
 #elif BUILDFLAG(IS_POSIX)
 typedef pid_t PlatformThreadId;
 #endif
