--- src/export/file.c.orig	2016-04-10 12:10:21 UTC
+++ src/export/file.c
@@ -644,7 +644,7 @@ template_open (DenemoProject * gui, Temp
     {
       if (system_example_path == NULL)
         {
-          system_example_path = g_build_filename (get_system_data_dir (), "examples", NULL);
+          system_example_path = g_build_filename (get_system_data_dir (), "..", "examples", "denemo", NULL);
           GDir *denemo_path = g_dir_open (system_example_path, 0, NULL);
           if (denemo_path == NULL)
             {
