--- tools/db_stress.cc.orig	2015-11-17 21:52:04 UTC
+++ tools/db_stress.cc
@@ -590,7 +590,7 @@ class Stats {
             "", bytes_mb, rate, (100*writes_)/done_, done_);
     fprintf(stdout, "%-12s: Wrote %ld times\n", "", writes_);
     fprintf(stdout, "%-12s: Deleted %ld times\n", "", deletes_);
-    fprintf(stdout, "%-12s: Single deleted %ld times\n", "", single_deletes_);
+    fprintf(stdout, "%-12s: Single deleted %zu times\n", "", single_deletes_);
     fprintf(stdout, "%-12s: %ld read and %ld found the key\n", "",
             gets_, founds_);
     fprintf(stdout, "%-12s: Prefix scanned %ld times\n", "", prefixes_);
