--- tools/rlesortmap.c.orig	1992-02-12 06:37:12.000000000 +0900
+++ tools/rlesortmap.c	2012-10-15 23:00:51.000000000 +0900
@@ -42,7 +42,7 @@
  * 	sense for pseudo-color input files, but the program will work
  * 	on any input file.
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
