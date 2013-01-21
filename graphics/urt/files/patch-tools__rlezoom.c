--- tools/rlezoom.c.orig	1992-01-24 05:56:16.000000000 +0900
+++ tools/rlezoom.c	2012-10-15 23:02:47.000000000 +0900
@@ -61,7 +61,7 @@
  *      into runs.  Write each line a number of times equal to the Y
  *      factor. 
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
