--- tools/rleldmap.c.orig	1992-08-06 23:11:41.000000000 +0900
+++ tools/rleldmap.c	2012-10-15 22:57:06.000000000 +0900
@@ -135,7 +135,7 @@
  *	the input file to the output file.  If stdin is empty (no input at
  *	all, an output RLE file with just a color map will be generated).
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
