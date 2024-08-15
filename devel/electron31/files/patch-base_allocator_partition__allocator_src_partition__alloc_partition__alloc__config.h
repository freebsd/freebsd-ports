--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_config.h.orig	2024-06-18 21:43:17 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_config.h
@@ -232,7 +232,7 @@ constexpr bool kUseLazyCommit = false;
 // On these platforms, lock all the partitions before fork(), and unlock after.
 // This may be required on more platforms in the future.
 #define PA_CONFIG_HAS_ATFORK_HANDLER() \
-  (BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+  (BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 
 // PartitionAlloc uses PartitionRootEnumerator to acquire all
 // PartitionRoots at BeforeFork and to release at AfterFork.
@@ -279,7 +279,7 @@ constexpr bool kUseLazyCommit = false;
 //
 // Also enabled on ARM64 macOS and iOS, as the 16kiB pages on this platform lead
 // to larger slot spans.
-#if BUILDFLAG(IS_LINUX) || (BUILDFLAG(IS_APPLE) && defined(ARCH_CPU_ARM64))
+#if BUILDFLAG(IS_LINUX) || (BUILDFLAG(IS_APPLE) && defined(ARCH_CPU_ARM64)) || BUILDFLAG(IS_BSD)
 #define PA_CONFIG_PREFER_SMALLER_SLOT_SPANS() 1
 #else
 #define PA_CONFIG_PREFER_SMALLER_SLOT_SPANS() 0
