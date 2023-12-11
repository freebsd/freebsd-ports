--- base/allocator/partition_allocator/partition_alloc_constants.h.orig	2023-10-19 19:57:58 UTC
+++ base/allocator/partition_allocator/partition_alloc_constants.h
@@ -95,7 +95,7 @@ PartitionPageShift() {
   return 18;  // 256 KiB
 }
 #elif (BUILDFLAG(IS_APPLE) && defined(ARCH_CPU_64_BITS)) || \
-    (BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64))
 PA_ALWAYS_INLINE PAGE_ALLOCATOR_CONSTANTS_DECLARE_CONSTEXPR size_t
 PartitionPageShift() {
   return PageAllocationGranularityShift() + 2;
@@ -297,7 +297,8 @@ constexpr size_t kNumPools = kMaxPoolHandle - 1;
 // 8GB for each of the glued pools).
 #if BUILDFLAG(HAS_64_BIT_POINTERS)
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(ENABLE_POINTER_COMPRESSION)
+    BUILDFLAG(ENABLE_POINTER_COMPRESSION) || \
+    BUILDFLAG(IS_BSD)
 constexpr size_t kPoolMaxSize = 8 * kGiB;
 #else
 constexpr size_t kPoolMaxSize = 16 * kGiB;
