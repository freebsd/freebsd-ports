--- tools/rleccube.c.orig	1992-04-30 23:11:54.000000000 +0900
+++ tools/rleccube.c	2012-10-15 22:52:09.000000000 +0900
@@ -66,7 +66,7 @@
  * Algorithm:
  * 	Pretty simple.
  */
-void
+int
 main( argc, argv)
 int argc;
 char **argv;
