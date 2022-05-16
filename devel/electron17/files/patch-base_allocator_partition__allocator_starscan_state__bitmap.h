--- base/allocator/partition_allocator/starscan/state_bitmap.h.orig	2022-05-11 07:16:46 UTC
+++ base/allocator/partition_allocator/starscan/state_bitmap.h
@@ -393,7 +393,7 @@ template <size_t PageSize, size_t PageAlignment, size_
 template <typename Filter,
           typename CallbackForwarder,
           typename Callback,
-          bool Clear>
+          bool ClearBits>
 inline void
 StateBitmap<PageSize, PageAlignment, AllocationAlignment>::IterateImpl(
     size_t epoch,
@@ -423,7 +423,7 @@ StateBitmap<PageSize, PageAlignment, AllocationAlignme
 
       callback_forwarder(callback, object_address, bits);
 
-      if (Clear) {
+      if (ClearBits) {
         // Clear the current bits.
         AsAtomicCell(cell_index)
             .fetch_and(clear_value_mask, std::memory_order_relaxed);
