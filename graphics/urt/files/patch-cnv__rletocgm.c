--- cnv/rletocgm.c.orig	1992-04-30 22:59:08.000000000 +0900
+++ cnv/rletocgm.c	2012-10-16 00:17:32.000000000 +0900
@@ -449,6 +449,7 @@
  * 	Repeatedly read from the input until the file EOF or an
  * 	error is encountered.
  */
+int
 main( argc, argv )
 int argc;
 char **argv;
