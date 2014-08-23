--- ./contigs.c.orig	2008-11-11 22:56:27.000000000 +0100
+++ ./contigs.c	2014-08-02 12:39:30.000000000 +0200
@@ -2115,6 +2115,7 @@
    contig1->base_segment = previous_base_segment;
 }
 
+void
 write_contigs()
 {
   char *our_alloc();
