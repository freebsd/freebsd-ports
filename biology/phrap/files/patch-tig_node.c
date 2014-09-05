--- ./tig_node.c.orig	2007-11-06 23:02:49.000000000 +0100
+++ ./tig_node.c	2014-08-02 12:39:30.000000000 +0200
@@ -138,6 +138,7 @@
   tig_node->best_stack_length[0] = tig_node->best_stack_length[1] = 0;
 }
 
+void
 alloc_edge(contig, orientation, pair, reverse)
      Contig *contig;
      int orientation, reverse;
@@ -176,6 +177,7 @@
   tig_node->edges[orientation] = edge;
 }
 
+void
 find_best_paths(gap_cutoff, LLR_reject_cutoff, LLR_join_cutoff)
      int gap_cutoff, LLR_reject_cutoff, LLR_join_cutoff;
 {
