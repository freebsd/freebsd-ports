--- src/tool_operate.c.orig	2023-03-20 11:38:42 UTC
+++ src/tool_operate.c
@@ -1106,20 +1106,7 @@ static CURLcode single_transfer(struct GlobalConfig *g
             DEBUGASSERT(!outs->filename);
           }
 
-          if(config->resume_from_current) {
-            /* We're told to continue from where we are now. Get the size
-               of the file as it is now and open it for append instead */
-            struct_stat fileinfo;
-            /* VMS -- Danger, the filesize is only valid for stream files */
-            if(0 == stat(per->outfile, &fileinfo))
-              /* set offset to current file size: */
-              config->resume_from = fileinfo.st_size;
-            else
-              /* let offset be 0 */
-              config->resume_from = 0;
-          }
-
-          if(config->resume_from) {
+          if(config->resume_from || config->resume_from_current) {
 #ifdef __VMS
             /* open file for output, forcing VMS output format into stream
                mode which is needed for stat() call above to always work. */
@@ -1136,6 +1123,19 @@ static CURLcode single_transfer(struct GlobalConfig *g
             }
             outs->fopened = TRUE;
             outs->stream = file;
+
+            if(config->resume_from_current) {
+              /* We're told to continue from where we are now. Get the size
+                 of the file as it is now */
+              struct_stat fileinfo;
+              if(0 == fstat(fileno(outs->stream), &fileinfo))
+                /* set offset to current file size: */
+                config->resume_from = fileinfo.st_size;
+              else
+                /* let offset be 0 */
+                config->resume_from = 0;
+            }
+
             outs->init = config->resume_from;
           }
           else {
