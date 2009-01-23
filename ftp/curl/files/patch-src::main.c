diff -urN -x .svn ../../vendor/curl/src/main.c ./src/main.c
--- ../../vendor/curl/src/main.c	2008-10-29 00:12:02.000000000 +0200
+++ ./src/main.c	2009-01-21 16:12:11.000000000 +0200
@@ -4313,31 +4313,32 @@
              (-1 == create_dir_hierarchy(outfile, config->errors)))
             return CURLE_WRITE_ERROR;
 
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
               return CURLE_WRITE_ERROR;
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
@@ -5288,12 +5289,13 @@
 static const char *
 msdosify (const char *file_name)
 {
-  static char dos_name[PATH_MAX*2];
+  static char dos_name[PATH_MAX + 16];
   static const char illegal_chars_dos[] = ".+, ;=[]|<>\\\":?*";
   static const char *illegal_chars_w95 = &illegal_chars_dos[8];
   int idx, dot_idx;
   const char *s = file_name;
   char *d = dos_name;
+  char *dlimit = dos_name + PATH_MAX;
   const char *illegal_aliens = illegal_chars_dos;
   size_t len = sizeof (illegal_chars_dos) - 1;
   int lfn = 0;
@@ -5314,7 +5316,7 @@
     *d++ = *s++;
   }
 
-  for (idx = 0, dot_idx = -1; *s; s++, d++) {
+  for (idx = 0, dot_idx = -1; *s && d < dlimit; s++, d++) {
     if (memchr (illegal_aliens, *s, len)) {
       /* Dots are special: DOS doesn't allow them as the leading character,
          and a file name cannot have more than a single dot.  We leave the
@@ -5371,6 +5373,10 @@
       idx++;
   }
 
+  if(d >= dlimit) {
+    /* should some kind of error be raised? */
+    d = dlimit - 1;
+  }
   *d = '\0';
   return dos_name;
 }
