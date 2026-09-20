--- src/core/searchcore.cpp.orig	2026-09-19 20:41:23 UTC
+++ src/core/searchcore.cpp
@@ -309,9 +309,14 @@ auto accumulate_slice_counts(struct searchinfo_s const
           auto const bits = View<unsigned char>{std::next(bitmap, first_byte),
                                                 slice_bitmap_bytes};
 #ifdef __x86_64__
+          // Not sure how to enable ssse3 without enabling other
+          // non-portable features.
+          // This code is only used rarely, so disable ssse3 for now.
+          // It won't affect performance much on the whole.
+          // https://github.com/torognes/vsearch/pull/497
           if (parameters.runtime.ssse3_present != 0)
             {
-              increment_counters_from_bitmap_ssse3(slice, bits);
+              increment_counters_from_bitmap_sse2(slice, bits);
             }
           else
             {
