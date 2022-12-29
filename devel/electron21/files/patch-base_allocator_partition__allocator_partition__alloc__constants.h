--- base/allocator/partition_allocator/partition_alloc_constants.h.orig	2022-09-24 10:57:32 UTC
+++ base/allocator/partition_allocator/partition_alloc_constants.h
@@ -91,7 +91,7 @@ PartitionPageShift() {
   return 18;  // 256 KiB
 }
 #elif (BUILDFLAG(IS_APPLE) && defined(ARCH_CPU_64_BITS)) || \
-    (BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64))
 PAGE_ALLOCATOR_CONSTANTS_DECLARE_CONSTEXPR PA_ALWAYS_INLINE size_t
 PartitionPageShift() {
   return PageAllocationGranularityShift() + 2;
@@ -270,7 +270,7 @@ constexpr size_t kNumPools = 3;
 // Special-case Android and iOS, which incur test failures with larger
 // GigaCage. Regardless, allocating >8GiB with malloc() on these platforms is
 // unrealistic as of 2022.
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 constexpr size_t kPoolMaxSize = 8 * kGiB;
 #else
 constexpr size_t kPoolMaxSize = 16 * kGiB;
