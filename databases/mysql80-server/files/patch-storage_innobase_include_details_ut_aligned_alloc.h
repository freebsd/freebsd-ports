--- storage/innobase/include/detail/ut/aligned_alloc.h.orig	2024-08-29 18:34:56.237736000 +0200
+++ storage/innobase/include/detail/ut/aligned_alloc.h	2024-08-29 18:35:34.091577000 +0200
@@ -55,7 +55,7 @@ struct Aligned_alloc_impl {
       whatever arbitrary data. See Aligned_alloc and Aligned_alloc_arr for
       exemplary usages of it.
    */
-  static constexpr uint32_t metadata_size = alignof(max_align_t);
+  static constexpr uint32_t metadata_size = alignof(max_align_t) < (2 * alignof(uint32_t)) ? (2 * alignof(uint32_t)) : alignof(max_align_t);
 
   /** Alias that we will be using to denote ptr to DATA segment. */
   using data_segment_ptr = void *;
