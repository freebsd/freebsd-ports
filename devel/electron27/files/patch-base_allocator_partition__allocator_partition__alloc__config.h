--- base/allocator/partition_allocator/partition_alloc_config.h.orig	2023-10-19 19:57:58 UTC
+++ base/allocator/partition_allocator/partition_alloc_config.h
@@ -94,7 +94,7 @@ static_assert(sizeof(void*) != 8, "");
 // POSIX is not only UNIX, e.g. macOS and other OSes. We do use Linux-specific
 // features such as futex(2).
 #define PA_CONFIG_HAS_LINUX_KERNEL() \
-  (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID))
+  (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
 
 // On some platforms, we implement locking by spinning in userspace, then going
 // into the kernel only if there is contention. This requires platform support,
@@ -237,7 +237,7 @@ constexpr bool kUseLazyCommit = false;
 // On these platforms, lock all the partitions before fork(), and unlock after.
 // This may be required on more platforms in the future.
 #define PA_CONFIG_HAS_ATFORK_HANDLER() \
-  (BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+  (BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 
 // PartitionAlloc uses PartitionRootEnumerator to acquire all
 // PartitionRoots at BeforeFork and to release at AfterFork.
@@ -284,7 +284,7 @@ constexpr bool kUseLazyCommit = false;
 // Also enabled on ARM64 macOS, as the 16kiB pages on this platform lead to
 // larger slot spans.
 #define PA_CONFIG_PREFER_SMALLER_SLOT_SPANS() \
-  (BUILDFLAG(IS_LINUX) || (BUILDFLAG(IS_MAC) && defined(ARCH_CPU_ARM64)))
+  (BUILDFLAG(IS_LINUX) || (BUILDFLAG(IS_MAC) && defined(ARCH_CPU_ARM64)) || BUILDFLAG(IS_BSD))
 
 // Enable shadow metadata.
 //
