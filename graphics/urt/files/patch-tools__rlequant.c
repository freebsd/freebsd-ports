--- tools/rlequant.c.orig	1993-11-20 04:13:48.000000000 +0900
+++ tools/rlequant.c	2012-10-15 22:58:46.000000000 +0900
@@ -136,7 +136,7 @@
  * 	images.  Because of this, the input cannot be coming from a
  * 	pipe.
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
