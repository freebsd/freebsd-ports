--- src/conf.c.orig	2000-03-06 20:43:13 UTC
+++ src/conf.c
@@ -207,11 +207,11 @@ void config_load (struct CONFIG *cfg)
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
