--- src/main.c.orig	2016-09-08 07:14:04 UTC
+++ src/main.c
@@ -256,7 +256,7 @@ cb_rstto_open_files (RsttoOpenFiles *rof
          */
         iter = rstto_main_window_get_iter (RSTTO_MAIN_WINDOW (rof->window));
 
-        if (file_type != G_FILE_TYPE_DIRECTORY && r_file != NULL)
+        if (r_file != NULL && file_type != G_FILE_TYPE_DIRECTORY)
         {
             /* Get the file's parent directory */
             p_file = g_file_get_parent (file);
