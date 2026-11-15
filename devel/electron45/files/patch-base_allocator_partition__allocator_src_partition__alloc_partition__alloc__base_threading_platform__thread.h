--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread.h.orig	2026-10-19 21:50:55 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread.h
@@ -39,6 +39,8 @@ typedef mach_port_t PlatformThreadId;
 typedef zx_handle_t PlatformThreadId;
 #elif PA_BUILDFLAG(IS_APPLE)
 typedef mach_port_t PlatformThreadId;
+#elif PA_BUILDFLAG(IS_BSD)
+typedef uint64_t PlatformThreadId;
 #elif PA_BUILDFLAG(IS_POSIX)
 typedef pid_t PlatformThreadId;
 #endif
