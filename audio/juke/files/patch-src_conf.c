--- ../juke.orig/src/conf.c	Thu Apr 15 21:44:53 1999
+++ ./src/conf.c	Sun May  2 12:18:07 1999
@@ -207,11 +207,11 @@
       return;
     }
   }
-  cfg->file_len = load_file ("/etc/juke.conf", (void **)&cfg->file);
+  cfg->file_len = load_file (CFG_RCFILE, (void **)&cfg->file);
   if (cfg->file_len != ERROR) {
     evaluate (cfg);
     if (! cfg->formats) {
-      fprintf (stderr, "error: No formats in /etc/juke.conf\n");
+      fprintf (stderr, "error: No formats in " CFG_RCFILE "\n");
       exit (ERROR);
     }
     build_arg_lists (cfg);
