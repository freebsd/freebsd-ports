--- cnv/rletoalias.c.orig	1992-04-30 22:58:47.000000000 +0900
+++ cnv/rletoalias.c	2012-10-13 07:07:29.000000000 +0900
@@ -108,7 +108,7 @@
  *      [None]
  */
 
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
