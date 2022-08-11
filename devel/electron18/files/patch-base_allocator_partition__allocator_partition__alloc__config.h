--- base/allocator/partition_allocator/partition_alloc_config.h.orig	2022-05-19 05:17:34 UTC
+++ base/allocator/partition_allocator/partition_alloc_config.h
@@ -59,7 +59,7 @@ static_assert(sizeof(void*) != 8, "");
 
 // POSIX is not only UNIX, e.g. macOS and other OSes. We do use Linux-specific
 // features such as futex(2).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #define PA_HAS_LINUX_KERNEL
 #endif
 
@@ -179,7 +179,7 @@ constexpr bool kUseLazyCommit = false;
 
 // On these platforms, lock all the partitions before fork(), and unlock after.
 // This may be required on more platforms in the future.
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define PA_HAS_ATFORK_HANDLER
 #endif
 
