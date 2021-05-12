--- base/allocator/partition_allocator/partition_alloc.cc.orig	2021-04-14 01:08:36 UTC
+++ base/allocator/partition_allocator/partition_alloc.cc
@@ -56,7 +56,12 @@ void PartitionAllocGlobalInit(OomFunction on_out_of_me
       "maximum direct mapped allocation");
 
   // Check that some of our zanier calculations worked out as expected.
+#if defined(__i386__) && defined(OS_FREEBSD)
+  // alignof(std::max_align_t) is only 4 on FreeBSD/i386
+  static_assert(kSmallestBucket >= kAlignment, "generic smallest bucket");
+#else
   static_assert(kSmallestBucket == kAlignment, "generic smallest bucket");
+#endif
   static_assert(kMaxBucketed == 983040, "generic max bucketed");
   STATIC_ASSERT_OR_PA_CHECK(
       MaxSystemPagesPerSlotSpan() < (1 << 8),
