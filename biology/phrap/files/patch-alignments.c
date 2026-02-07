--- ./alignments.c.orig	2009-04-18 23:07:41.000000000 +0200
+++ ./alignments.c	2014-08-02 12:39:30.000000000 +0200
@@ -591,6 +591,7 @@
   return adj_score;
 }
 
+void
 print_alignment(profile)
      Profile *profile;
 {
