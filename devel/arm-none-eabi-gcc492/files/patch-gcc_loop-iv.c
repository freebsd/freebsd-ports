--- gcc/loop-iv.c.orig	2014-01-17 10:47:59 UTC
+++ gcc/loop-iv.c
@@ -2297,7 +2297,7 @@ determine_max_iter (struct loop *loop, s
   if (andmax)
     nmax = MIN (nmax, andmax);
   if (dump_file)
-    fprintf (dump_file, ";; Determined upper bound "HOST_WIDEST_INT_PRINT_DEC".\n",
+    fprintf (dump_file, ";; Determined upper bound " HOST_WIDEST_INT_PRINT_DEC ".\n",
 	     nmax);
   return nmax;
 }
