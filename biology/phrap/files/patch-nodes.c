--- ./nodes.c.orig	2008-08-31 03:44:15.000000000 +0200
+++ ./nodes.c	2014-08-02 12:39:30.000000000 +0200
@@ -31,6 +31,8 @@
 extern Parameters *parameters; /* exported */
 extern double *scaled_err_probs;
 int *contig_graph_weights;
+
+void nr_tarjan(int);
  
 set_contig_graph_weights()
 {
@@ -679,6 +681,7 @@
   curr_state->calling_point = calling_point;
 }
     
+void
 nr_tarjan(k) 
      int k;
 {
