--- tools/rlestereo.c.orig	1992-04-30 23:14:08.000000000 +0900
+++ tools/rlestereo.c	2012-10-15 23:02:05.000000000 +0900
@@ -79,7 +79,7 @@
  *	-r scale	Scale factor for right-eye image (default 1.0).
  */
 
-void
+int
 main(argc, argv)
 int argc;
 char **argv;
