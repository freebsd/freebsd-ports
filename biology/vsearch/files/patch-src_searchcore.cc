--- src/searchcore.cc.orig	2024-09-26 10:48:55 UTC
+++ src/searchcore.cc
@@ -239,9 +239,14 @@ auto search_topscores(struct searchinfo_s * si) -> voi
       if (bitmap)
         {
 #ifdef __x86_64__
+	  // Not sure how to enable ssse3 without enabling other
+	  // non-portable features.
+	  // This code is only used rarely, so disable ssse3 for now.
+	  // It won't affect performance much on the whole.
+	  // https://github.com/torognes/vsearch/pull/497
           if (ssse3_present)
             {
-              increment_counters_from_bitmap_ssse3(si->kmers,
+              increment_counters_from_bitmap_sse2(si->kmers,
                                                    bitmap, indexed_count);
             }
           else
