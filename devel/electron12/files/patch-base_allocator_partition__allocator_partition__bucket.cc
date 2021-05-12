--- base/allocator/partition_allocator/partition_bucket.cc.orig	2021-04-14 01:08:36 UTC
+++ base/allocator/partition_allocator/partition_bucket.cc
@@ -66,27 +66,33 @@ PartitionDirectMap(PartitionRoot<thread_safe>* root, i
   metadata->extent.root = root;
   // The new structures are all located inside a fresh system page so they
   // will all be zeroed out. These DCHECKs are for documentation.
+#if !defined(OS_FREEBSD)
   PA_DCHECK(!metadata->extent.super_page_base);
   PA_DCHECK(!metadata->extent.super_pages_end);
   PA_DCHECK(!metadata->extent.next);
+#endif
   PA_DCHECK(PartitionPage<thread_safe>::FromPointerNoAlignmentCheck(slot) ==
             &metadata->page);
 
   auto* page = &metadata->page;
+#if !defined(OS_FREEBSD)
   PA_DCHECK(!page->slot_span_metadata_offset);
   PA_DCHECK(!page->slot_span_metadata.next_slot_span);
   PA_DCHECK(!page->slot_span_metadata.num_allocated_slots);
   PA_DCHECK(!page->slot_span_metadata.num_unprovisioned_slots);
   PA_DCHECK(!page->slot_span_metadata.empty_cache_index);
+#endif
   page->slot_span_metadata.bucket = &metadata->bucket;
   auto* next_entry = new (slot) PartitionFreelistEntry();
   page->slot_span_metadata.SetFreelistHead(next_entry);
 
+#if !defined(OS_FREEBSD)
   PA_DCHECK(!metadata->bucket.active_slot_spans_head);
   PA_DCHECK(!metadata->bucket.empty_slot_spans_head);
   PA_DCHECK(!metadata->bucket.decommitted_slot_spans_head);
   PA_DCHECK(!metadata->bucket.num_system_pages_per_slot_span);
   PA_DCHECK(!metadata->bucket.num_full_slot_spans);
+#endif
   metadata->bucket.slot_size = slot_size;
 
   auto* map_extent = &metadata->direct_map_extent;
