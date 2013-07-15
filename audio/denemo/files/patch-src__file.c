--- src/file.c.orig
+++ src/file.c
@@ -571,7 +571,7 @@
     {
       if (system_example_path == NULL)
         {
-          system_example_path = g_build_filename (get_data_dir (), "examples", NULL);
+          system_example_path = g_build_filename (get_data_dir (), "..", "examples", NULL);
           GDir *denemo_path = g_dir_open (system_example_path, 0, NULL);
           if (denemo_path == NULL)
             {
