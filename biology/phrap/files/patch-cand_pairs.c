--- ./cand_pairs.c.orig	2008-08-31 03:02:56.000000000 +0200
+++ ./cand_pairs.c	2014-08-02 12:39:30.000000000 +0200
@@ -38,6 +38,7 @@
 
 static int num_cand_pairs, num_dups, num_repeat_rejected_pairs;
 
+void
 cluster_pairs(entry1, entry2, start1, start2, reverse, rev_store_flag)
      int entry1, entry2, start1, start2;
      int reverse, rev_store_flag;
@@ -74,6 +75,7 @@
   set_equiv_class(entry, final_class);
 }
 
+void
 make_new_cand_pair(entry1, entry2, start1, start2, reverse, rev_store_flag)
      int entry1, entry2, start1, start2;
      int reverse, rev_store_flag;
