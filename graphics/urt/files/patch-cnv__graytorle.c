--- cnv/graytorle.c.orig	1993-04-21 23:42:40.000000000 +0900
+++ cnv/graytorle.c	2012-10-15 22:31:19.000000000 +0900
@@ -39,7 +39,7 @@
  *    -a		Uses first input file as alpha channel.
  */
 
-void
+int
 main(argc, argv)
 int  argc;
 char *argv[];
