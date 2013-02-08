--- tools/smush.c.orig	1992-01-24 05:56:39.000000000 +0900
+++ tools/smush.c	2012-10-15 23:03:11.000000000 +0900
@@ -18,7 +18,7 @@
 
 char *progname;
 
-void
+int
 main(argc, argv)
 int  argc;
 char *argv[];
