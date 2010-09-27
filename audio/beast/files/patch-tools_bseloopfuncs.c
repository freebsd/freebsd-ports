--- tools/bseloopfuncs.c.orig	2010-02-14 00:47:12.000000000 +0000
+++ tools/bseloopfuncs.c	2010-09-15 12:05:05.000000000 +0000
@@ -526,7 +526,7 @@
       ep = sp + minll;
       {
         gdouble score = score_headloop (dhandle, sp, ep - sp, config->block_length / 2, G_MAXDOUBLE);
-        g_print ("%u %.17g\n", sp - block, score);
+        g_print ("%lu %.17g\n", sp - block, score);
         continue;
         if (score <= config->score)
           {
@@ -555,7 +555,7 @@
       for (ep = sp + minll; ep < cstart; ep++)
         {
           gdouble score = score_headloop (dhandle, sp, ep - sp, config->block_length / 2, config->score);
-          g_print ("%u %.17g\n", ep - sp, score);
+          g_print ("%lu %.17g\n", ep - sp, score);
           continue;
           if (score <= config->score)
             {
