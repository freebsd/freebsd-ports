--- src/main.c.orig	2015-02-10 23:31:49.000000000 +0200
+++ src/main.c	2015-03-06 21:55:03.975252490 +0200
@@ -1272,6 +1272,9 @@
   if (opt.verbose == -1)
     opt.verbose = !opt.quiet;
 
+  if (opt.quiet && opt.show_progress == -1)
+    opt.show_progress = false;
+
   /* Sanity checks.  */
   if (opt.verbose && opt.quiet)
     {
