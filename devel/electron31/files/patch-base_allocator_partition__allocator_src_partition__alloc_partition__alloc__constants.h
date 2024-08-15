--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h.orig	2024-06-18 21:43:17 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h
@@ -316,7 +316,7 @@ constexpr size_t kNumPools = kMaxPoolHandle - 1;
 // 8GB for each of the glued pools).
 #if PA_BUILDFLAG(HAS_64_BIT_POINTERS)
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || \
-    PA_BUILDFLAG(ENABLE_POINTER_COMPRESSION)
+    PA_BUILDFLAG(ENABLE_POINTER_COMPRESSION) || BUILDFLAG(IS_BSD)
 constexpr size_t kPoolMaxSize = 8 * kGiB;
 #else
 constexpr size_t kPoolMaxSize = 16 * kGiB;
