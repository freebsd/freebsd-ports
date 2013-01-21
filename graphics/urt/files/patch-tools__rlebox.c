--- tools/rlebox.c.orig	1992-04-30 23:11:25.000000000 +0900
+++ tools/rlebox.c	2012-10-15 22:52:09.000000000 +0900
@@ -40,7 +40,7 @@
  * 	Read the image file and find the smallest and largest X and Y
  *	coordinates of real image data.  Use raw interface for speed.
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
