--- src/gabufr.c.orig	2014-05-24 07:48:38.000000000 -0700
+++ src/gabufr.c	2014-05-24 07:49:10.000000000 -0700
@@ -129,6 +129,7 @@
 }  
 
 /* prints a full description of a varid, expanding sequence contents*/
+void
 gabufr_print_varid (gabufr_varid *varid, int indent) {
   gabufr_varid * seq_varid;
   gabufr_varinf * varinf;
