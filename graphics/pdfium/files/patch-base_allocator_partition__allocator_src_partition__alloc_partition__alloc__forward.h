-- Ensure the minimum partition allocator alignment is large enough to hold a
-- freelist entry (two pointers), fixing build failures on FreeBSD/powerpc64
-- where the fundamental alignment is smaller.
--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_forward.h.orig	1970-01-01 00:00:00 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_forward.h
@@ -28,9 +28,14 @@ namespace internal {
 // the second one 16. We could technically return something different for
 // malloc() and operator new(), but this would complicate things, and most of
 // our allocations are presumably coming from operator new() anyway.
+//
+// The smallest bucket must also hold a freelist entry, which is two pointers
+// wide, so never go below that even where the fundamental alignment is smaller
+// (FreeBSD/powerpc64, whose long double is 64 bits wide).
 constexpr inline size_t kAlignment =
-    IntegralMax(alignof(max_align_t),
-                static_cast<size_t>(__STDCPP_DEFAULT_NEW_ALIGNMENT__));
+    IntegralMax(IntegralMax(alignof(max_align_t),
+                            static_cast<size_t>(__STDCPP_DEFAULT_NEW_ALIGNMENT__)),
+                2 * sizeof(void*));
 static_assert(std::has_single_bit(kAlignment),
               "Alignment must be power of two.");
 static_assert(kAlignment <= 16,
