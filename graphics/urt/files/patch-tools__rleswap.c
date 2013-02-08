--- tools/rleswap.c.orig	1992-07-06 13:50:59.000000000 +0900
+++ tools/rleswap.c	2012-10-15 23:02:27.000000000 +0900
@@ -99,7 +99,7 @@
  * Algorithm:
  *	[None]
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
