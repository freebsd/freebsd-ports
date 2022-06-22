--- base/allocator/partition_allocator/partition_root.h.orig	2022-05-19 05:17:34 UTC
+++ base/allocator/partition_allocator/partition_root.h
@@ -1071,7 +1071,7 @@ ALWAYS_INLINE void PartitionRoot<thread_safe>::FreeNoH
   // essentially).
 #if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) &&              \
     ((BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMECAST)) || \
-     (BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_64_BITS)))
+     ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_64_BITS)))
   PA_CHECK(IsManagedByPartitionAlloc(object_addr));
 #endif
 
