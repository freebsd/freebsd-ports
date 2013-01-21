--- tools/unslice.c.orig	1992-04-30 23:14:55.000000000 +0900
+++ tools/unslice.c	2012-10-15 23:04:35.000000000 +0900
@@ -51,7 +51,7 @@
 char *progname;
 char **gargv;
 
-void
+int
 main (argc, argv)
 int argc;
 char **argv;
