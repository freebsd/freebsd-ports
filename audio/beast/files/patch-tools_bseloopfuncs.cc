--- tools/bseloopfuncs.cc.orig	2013-01-19 00:23:42 UTC
+++ tools/bseloopfuncs.cc
@@ -469,7 +469,7 @@ gsl_data_find_loop2 (GslDataHandle     *
       ep = sp + minll;
       {
         gdouble score = score_headloop (dhandle, sp, ep - sp, config->block_length / 2, G_MAXDOUBLE);
-        g_print ("%u %.17g\n", sp - block, score);
+        g_print ("%lu %.17g\n", sp - block, score);
         continue;
         if (score <= config->score)
           {
@@ -496,7 +496,7 @@ gsl_data_find_loop2 (GslDataHandle     *
       for (ep = sp + minll; ep < cstart; ep++)
         {
           gdouble score = score_headloop (dhandle, sp, ep - sp, config->block_length / 2, config->score);
-          g_print ("%u %.17g\n", ep - sp, score);
+          g_print ("%lu %.17g\n", ep - sp, score);
           continue;
           if (score <= config->score)
             {
