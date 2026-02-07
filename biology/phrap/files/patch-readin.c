--- ./readin.c.orig	2008-11-11 20:33:41.000000000 +0100
+++ ./readin.c	2014-08-02 12:39:30.000000000 +0200
@@ -31,6 +31,7 @@
 /* read in sequence files, initialize array of aligned read info, and log file of ancillary information,
  and find pairwise matches */
 
+void
 readin_and_match()
 {
   File *file;
