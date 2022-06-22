--- base/allocator/partition_allocator/partition_page.h.orig	2022-06-04 07:17:41 UTC
+++ base/allocator/partition_allocator/partition_page.h
@@ -128,7 +128,8 @@ struct __attribute__((packed)) SlotSpanMetadata {
   PartitionBucket<thread_safe>* const bucket = nullptr;
 
   // CHECK()ed in AllocNewSlotSpan().
-#if defined(PA_HAS_64_BITS_POINTERS) && BUILDFLAG(IS_APPLE)
+#if (defined(PA_HAS_64_BITS_POINTERS) && BUILDFLAG(IS_APPLE)) || \
+    (BUILDFLAG(IS_FREEBSD) && defined(__i386__))
   // System page size is not a constant on Apple OSes, but is either 4 or 16kiB
   // (1 << 12 or 1 << 14), as checked in PartitionRoot::Init(). And
   // PartitionPageSize() is 4 times the OS page size.
@@ -148,7 +149,9 @@ struct __attribute__((packed)) SlotSpanMetadata {
 #endif  // defined(PA_HAS_64_BITS_POINTERS) && BUILDFLAG(IS_APPLE)
   // The maximum number of bits needed to cover all currently supported OSes.
   static constexpr size_t kMaxSlotsPerSlotSpanBits = 13;
+#if !BUILDFLAG(IS_FREEBSD) && defined(__i386__)
   static_assert(kMaxSlotsPerSlotSpan < (1 << kMaxSlotsPerSlotSpanBits), "");
+#endif
 
   // |marked_full| isn't equivalent to being full. Slot span is marked as full
   // iff it isn't on the active slot span list (or any other list).
