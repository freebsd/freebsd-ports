--- src/tool_operate.c.orig	2013-08-01 04:53:34.000000000 +0800
+++ src/tool_operate.c	2013-08-17 18:25:00.139780776 +0800
@@ -709,20 +709,7 @@
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
@@ -730,7 +717,8 @@
                                "ctx=stm", "rfm=stmlf", "rat=cr", "mrs=0");
 #else
             /* open file for output: */
-            FILE *file = fopen(outfile, config->resume_from?"ab":"wb");
+            /* (always open for appending, it has no effect on new files) */
+            FILE *file = fopen(outfile, "ab");
 #endif
             if(!file) {
               helpf(config->errors, "Can't open '%s'!\n", outfile);
@@ -739,6 +727,19 @@
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
