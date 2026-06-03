--- src/searchcore.cc.orig	2025-10-05 12:35:57 UTC
+++ src/searchcore.cc
@@ -285,9 +285,14 @@ auto search_topscores(struct searchinfo_s * searchinfo
       if (bitmap != nullptr)
         {
 #ifdef __x86_64__
+          // Not sure how to enable ssse3 without enabling other
+          // non-portable features.
+          // This code is only used rarely, so disable ssse3 for now.
+          // It won't affect performance much on the whole.
+          // https://github.com/torognes/vsearch/pull/497
           if (ssse3_present != 0)
             {
-              increment_counters_from_bitmap_ssse3(searchinfo->kmers,
+              increment_counters_from_bitmap_sse2(searchinfo->kmers,
                                                    bitmap, indexed_count);
             }
           else
