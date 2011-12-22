--- mscompress.c.orig	2011-12-22 00:20:22.000000000 +0800
+++ mscompress.c	2011-12-22 00:20:29.000000000 +0800
@@ -306,7 +306,7 @@ usage (char *progname)
   exit (0);
 }
 
-void
+int
 main (int argc, char **argv)
 {
   int in, out;
