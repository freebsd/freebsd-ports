--- gcc/loop-iv.c.orig	2013-04-23 19:36:20 UTC
+++ gcc/loop-iv.c
@@ -2292,7 +2292,7 @@ determine_max_iter (struct loop *loop, s
   if (andmax)
     nmax = MIN (nmax, andmax);
   if (dump_file)
-    fprintf (dump_file, ";; Determined upper bound "HOST_WIDEST_INT_PRINT_DEC".\n",
+    fprintf (dump_file, ";; Determined upper bound " HOST_WIDEST_INT_PRINT_DEC ".\n",
 	     nmax);
   return nmax;
 }
