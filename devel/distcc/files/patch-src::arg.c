--- src/arg.c.orig	Thu Aug 15 10:52:19 2002
+++ src/arg.c	Sun Aug 25 23:32:17 2002
@@ -200,12 +200,13 @@
         /* FIXME: This doesn't handle a.out, but that doesn't matter.
          */
         char *ofile;
-        if (seen_opt_c) {
-            if (dcc_output_from_source(*input_file, ".o", &ofile))
-                return -1;
-        } else if (seen_opt_s) {
+        /* -S takes precedence over -c.  */
+        if (seen_opt_s) {
             if (dcc_output_from_source(*input_file, ".s", &ofile))
                 return -1; 
+        } else if (seen_opt_c) {
+            if (dcc_output_from_source(*input_file, ".o", &ofile))
+                return -1;
         } else {
             rs_log_crit("this can't be happening(%d)!", __LINE__);
             return -1;
