--- tools/rleselect.c.orig	1992-04-30 23:13:32.000000000 +0900
+++ tools/rleselect.c	2012-10-15 22:59:31.000000000 +0900
@@ -78,7 +78,7 @@
  * 	specially.)  Read images, skipping if they are not in the
  * 	list, and copying if they are.
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
