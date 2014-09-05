--- ./weibull.c.orig	2008-07-29 20:06:24.000000000 +0200
+++ ./weibull.c	2014-08-02 12:39:30.000000000 +0200
@@ -77,6 +77,7 @@
   z_cutoff = Z_CUTOFF;
 }
 
+void
 update_hist(score_entry, z_flag)
      Score_entry *score_entry;
      int z_flag;
@@ -103,6 +104,7 @@
   score2_sums[length] += score * score;
 }  
 
+void
 prune_hist(score_entry)
      Score_entry *score_entry;
 {
