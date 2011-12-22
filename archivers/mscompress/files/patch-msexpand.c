--- msexpand.c.orig	2011-12-22 00:20:38.000000000 +0800
+++ msexpand.c	2011-12-22 00:20:44.000000000 +0800
@@ -215,7 +215,7 @@ usage (char *progname)
   exit (0);
 }
 
-void
+int
 main (int argc, char **argv)
 {
   int in, out;
