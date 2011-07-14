--- utils/fix132x43.c.orig	2011-07-01 01:43:39.000000000 +0200
+++ utils/fix132x43.c	2011-07-01 01:43:55.000000000 +0200
@@ -54,7 +54,7 @@
 static void fixfont (int);
 
 
-void
+int
 main (int argc, char *argv[])
 {
   int vgaIOBase;
