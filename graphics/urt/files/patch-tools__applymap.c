--- tools/applymap.c.orig	1995-05-03 01:51:29.000000000 +0900
+++ tools/applymap.c	2012-10-15 22:52:09.000000000 +0900
@@ -62,7 +62,7 @@
  * Algorithm:
  *	[None]
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
