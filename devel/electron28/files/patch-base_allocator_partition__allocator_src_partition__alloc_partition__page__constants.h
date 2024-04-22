--- base/allocator/partition_allocator/src/partition_alloc/partition_page_constants.h.orig	2023-11-29 21:39:39 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_page_constants.h
@@ -16,7 +16,7 @@ static constexpr size_t kMaxSlotsPerSlotSpan = 4 * (1 
 // (1 << 12 or 1 << 14), as checked in PartitionRoot::Init(). And
 // PartitionPageSize() is 4 times the OS page size.
 static constexpr size_t kMaxSlotsPerSlotSpan = 4 * (1 << 14) / kSmallestBucket;
-#elif BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 // System page size can be 4, 16, or 64 kiB on Linux on arm64. 64 kiB is
 // currently (kMaxSlotsPerSlotSpanBits == 13) not supported by the code,
 // so we use the 16 kiB maximum (64 kiB will crash).
