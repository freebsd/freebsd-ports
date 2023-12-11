--- base/allocator/partition_allocator/partition_alloc_base/threading/platform_thread_internal_posix.h.orig	2022-07-22 17:30:31 UTC
+++ base/allocator/partition_allocator/partition_alloc_base/threading/platform_thread_internal_posix.h
@@ -10,7 +10,7 @@
 
 namespace partition_alloc::internal::base::internal {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Current thread id is cached in thread local storage for performance reasons.
 // In some rare cases it's important to invalidate that cache explicitly (e.g.
 // after going through clone() syscall which does not call pthread_atfork()
