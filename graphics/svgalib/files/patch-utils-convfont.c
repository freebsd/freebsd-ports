--- utils/convfont.c.orig	2011-07-01 01:39:01.000000000 +0200
+++ utils/convfont.c	2011-07-01 01:39:11.000000000 +0200
@@ -14,7 +14,7 @@
 FILE *tf;
 
 
-void
+int
 main (int argc, char **argv)
 {
   int i;
