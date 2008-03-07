--- tools/bseloopfuncs.c.orig	2008-03-07 20:07:54.000000000 +0100
+++ tools/bseloopfuncs.c	2008-03-07 20:11:50.000000000 +0100
@@ -18,6 +18,7 @@
  */
 #include "bseloopfuncs.h"
 #include <bse/gsldatacache.h>
+#include <signal.h>
 #include <string.h>
 #include <stdio.h>
 #include <math.h>
@@ -527,7 +528,7 @@
       ep = sp + minll;
       {
         gdouble score = score_headloop (dhandle, sp, ep - sp, config->block_length / 2, G_MAXDOUBLE);
-        g_print ("%u %.17g\n", sp - block, score);
+        g_print ("%lu %.17g\n", sp - block, score);
         continue;
         if (score <= config->score)
           {
