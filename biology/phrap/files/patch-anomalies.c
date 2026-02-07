--- ./anomalies.c.orig	2008-11-10 06:02:00.000000000 +0100
+++ ./anomalies.c	2014-08-02 12:39:30.000000000 +0200
@@ -28,6 +28,8 @@
 extern Parameters *parameters;
 extern int num_pairs, t_num_entries;
 
+void visit_cand_pairs_dups(int, Cand_pair *);
+
 #define MAX_CHIMERA_GAP 30  /* maximum gap between distinct confirmed segments for 
 			       putative chimeras */
 compare_pair_entries(pair_1, pair_2)
@@ -830,6 +832,7 @@
   notify(" Done\n");
 }
 
+void
 visit_cand_pairs_dups(entry1, pair)
      int entry1;
      Cand_pair *pair;
