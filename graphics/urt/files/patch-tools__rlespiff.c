--- tools/rlespiff.c.orig	1992-04-30 23:13:47.000000000 +0900
+++ tools/rlespiff.c	2012-10-15 23:01:13.000000000 +0900
@@ -56,7 +56,7 @@
  * 	Then "rerun" the input, mapping the pixel values and writing
  * 	them to the output file.
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
