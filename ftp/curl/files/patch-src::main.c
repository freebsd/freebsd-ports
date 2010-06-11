Description: Use fstat() instead of stat() to avoid a race condition.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-06-11

--- a/src/main.c
+++ b/src/main.c
@@ -4658,33 +4658,34 @@
             break;
           }
 
-          if(config->resume_from_current) {
-            /* We're told to continue from where we are now. Get the
-               size of the file as it is now and open it for append instead */
-
-            struct_stat fileinfo;
-
-            /* VMS -- Danger, the filesize is only valid for stream files */
-            if(0 == stat(outfile, &fileinfo))
-              /* set offset to current file size: */
-              config->resume_from = fileinfo.st_size;
-            else
-              /* let offset be 0 */
-              config->resume_from = 0;
-          }
-
           outs.filename = outfile;
 
-          if(config->resume_from) {
-            outs.init = config->resume_from;
+          if(config->resume_from || config->resume_from_current) {
             /* open file for output: */
-            outs.stream=(FILE *) fopen(outfile, config->resume_from?"ab":"wb");
+	    /* (always open for appending, it has no effect on new files) */
+            outs.stream=(FILE *) fopen(outfile, "ab");
             if (!outs.stream) {
               helpf(config->errors, "Can't open '%s'!\n", outfile);
               free(url);
               res = CURLE_WRITE_ERROR;
               break;
             }
+
+	    if(config->resume_from_current) {
+	      /* We're told to continue from where we are now. Get the
+                 size of the file as it is now */
+
+	      struct_stat fileinfo;
+
+              if(0 == fstat(fileno(outs.stream), &fileinfo))
+                /* set offset to current file size: */
+                config->resume_from = fileinfo.st_size;
+              else
+                /* let offset be 0 */
+                config->resume_from = 0;
+	    }
+
+            outs.init = config->resume_from;
           }
           else {
             outs.stream = NULL; /* open when needed */
