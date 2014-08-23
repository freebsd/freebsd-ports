--- ./call_subs.c.orig	1999-01-17 00:42:56.000000000 +0100
+++ ./call_subs.c	2014-08-02 12:39:30.000000000 +0200
@@ -26,15 +26,13 @@
 
 extern Parameters *parameters; 
 
+void
 call_write_exp_files(n_sing, n_contigs, contig_ptrs)
      int n_sing, n_contigs;
      Contig **contig_ptrs;
 {
 #if defined(GCPHRAP)
   write_exp_files(n_sing, n_contigs, contig_ptrs);
-  return;
-#else
-  return;
 #endif
 }
 
