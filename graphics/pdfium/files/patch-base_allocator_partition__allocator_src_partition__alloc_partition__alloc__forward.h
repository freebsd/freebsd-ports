--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_forward.h.orig	2026-10-20 01:48:02 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_forward.h
@@ -30,9 +30,14 @@
 // the second one 16. We could technically return something different for
 // malloc() and operator new(), but this would complicate things, and most of
 // our allocations are presumably coming from operator new() anyway.
+//
+// The smallest bucket must also hold a freelist entry, which is two pointers
+// wide, so never go below that even where the fundamental alignment is smaller
+// (FreeBSD/powerpc64, whose long double is 64 bits wide).
 constexpr inline size_t kAlignment =
-    std::max(alignof(max_align_t),
-             static_cast<size_t>(__STDCPP_DEFAULT_NEW_ALIGNMENT__));
+    std::max({alignof(max_align_t),
+              static_cast<size_t>(__STDCPP_DEFAULT_NEW_ALIGNMENT__),
+              2 * sizeof(void*)});
 static_assert(std::has_single_bit(kAlignment),
               "Alignment must be power of two.");
 static_assert(kAlignment <= 16,
