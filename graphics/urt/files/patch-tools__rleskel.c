--- tools/rleskel.c.orig	1992-01-24 05:45:50.000000000 +0900
+++ tools/rleskel.c	2012-10-15 23:00:23.000000000 +0900
@@ -51,6 +51,7 @@
  * 	Repeatedly read from the input until the file EOF or an
  * 	error is encountered.
  */
+int
 main( argc, argv )
 int argc;
 char **argv;
