--- msexpand.c.orig	2000-04-15 13:15:45 UTC
+++ msexpand.c
@@ -215,7 +215,7 @@ usage (char *progname)
   exit (0);
 }
 
-void
+int
 main (int argc, char **argv)
 {
   int in, out;
