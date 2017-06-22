--- src/tool_operate.c.orig	2017-06-09 09:57:41 UTC
+++ src/tool_operate.c
@@ -654,20 +654,7 @@ static CURLcode operate_do(struct Global
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
 #ifdef __VMS
             /* open file for output, forcing VMS output format into stream
                mode which is needed for stat() call above to always work. */
@@ -675,7 +662,8 @@ static CURLcode operate_do(struct Global
                                "ctx=stm", "rfm=stmlf", "rat=cr", "mrs=0");
 #else
             /* open file for output: */
-            FILE *file = fopen(outfile, config->resume_from?"ab":"wb");
+            /* (always open for appending, it has no effect on new files) */
+            FILE *file = fopen(outfile, "ab");
 #endif
             if(!file) {
               helpf(global->errors, "Can't open '%s'!\n", outfile);
@@ -684,6 +672,19 @@ static CURLcode operate_do(struct Global
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
