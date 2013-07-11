--- src/tool_operate.c.orig	2012-07-24 01:59:20.000000000 +0800
+++ src/tool_operate.c	2012-09-22 20:54:44.439408357 +0800
@@ -653,22 +653,10 @@
             DEBUGASSERT(!outs.filename);
           }
 
-          if(config->resume_from_current) {
-            /* We're told to continue from where we are now. Get the size
-               of the file as it is now and open it for append instead */
-            struct_stat fileinfo;
-            /* VMS -- Danger, the filesize is only valid for stream files */
-            if(0 == stat(outfile, &fileinfo))
-              /* set offset to current file size: */
-              config->resume_from = fileinfo.st_size;
-            else
-              /* let offset be 0 */
-              config->resume_from = 0;
-          }
-
-          if(config->resume_from) {
+          if(config->resume_from || config->resume_from_current) {
             /* open file for output: */
-            FILE *file = fopen(outfile, config->resume_from?"ab":"wb");
+            /* (always open for appending, it has no effect on new files) */
+            FILE *file = fopen(outfile, "ab");
             if(!file) {
               helpf(config->errors, "Can't open '%s'!\n", outfile);
               res = CURLE_WRITE_ERROR;
@@ -676,6 +664,19 @@
             }
             outs.fopened = TRUE;
             outs.stream = file;
+
+            if(config->resume_from_current) {
+              /* We're told to continue from where we are now. Get the size
+                 of the file as it is now */
+              struct_stat fileinfo;
+              if(0 == fstat(fileno(outs.stream), &fileinfo))
+                /* set offset to current file size: */
+                config->resume_from = fileinfo.st_size;
+              else
+                /* let offset be 0 */
+                config->resume_from = 0;
+            }
+
             outs.init = config->resume_from;
           }
           else {
