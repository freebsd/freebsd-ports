--- ./names.c.orig	2007-11-06 23:03:53.000000000 +0100
+++ ./names.c	2014-08-02 12:39:30.000000000 +0200
@@ -30,6 +30,8 @@
 
 #define MAX_SUBCLONE_HIST 101
 
+void print_contig_chains();
+
 set_delims()
 {
   subclone_delim = parameters->subclone_delim;
@@ -1014,6 +1016,7 @@
 
 /* greedy algorithm for finding chains of contigs */
 /* NEED TO LOOK SYSTEMATICALLY FOR CIRCULAR CHAINS, AND BREAK THEM */
+void
 print_contig_chains()
 {
   Link *link;
