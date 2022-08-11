--- base/allocator/partition_allocator/partition_alloc.cc.orig	2022-05-25 04:00:42 UTC
+++ base/allocator/partition_allocator/partition_alloc.cc
@@ -63,8 +63,14 @@ void PartitionAllocGlobalInit(OomFunction on_out_of_me
       "maximum direct mapped allocation");
 
   // Check that some of our zanier calculations worked out as expected.
+#if defined(__i386__) && defined(OS_FREEBSD)
+  // alignof(std::max_align_t) is only 4 on FreeBSD/i386
+  static_assert(internal::kSmallestBucket >= internal::kAlignment,
+                "generic smallest bucket");
+#else
   static_assert(internal::kSmallestBucket == internal::kAlignment,
                 "generic smallest bucket");
+#endif
   static_assert(internal::kMaxBucketed == 917504, "generic max bucketed");
   STATIC_ASSERT_OR_PA_CHECK(
       internal::MaxSystemPagesPerRegularSlotSpan() <= 16,
