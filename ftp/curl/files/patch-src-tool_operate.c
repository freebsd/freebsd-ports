--- src/tool_operate.c.orig	2012-01-23 23:31:30.000000000 +0800
+++ src/tool_operate.c	2012-02-26 17:40:00.117907281 +0800
@@ -580,22 +580,10 @@
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
@@ -603,6 +591,19 @@
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
