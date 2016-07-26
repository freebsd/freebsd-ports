--- mscompress.c.orig	2000-04-15 13:15:38 UTC
+++ mscompress.c
@@ -306,7 +306,7 @@ usage (char *progname)
   exit (0);
 }
 
-void
+int
 main (int argc, char **argv)
 {
   int in, out;
