--- src/file.c.orig
+++ src/file.c
@@ -556,7 +556,7 @@
     default_template_path = local_template_path;   
   } else if(local==EXAMPLE){
     if(system_example_path==NULL) {
-      system_example_path = g_build_filename (get_data_dir (), "examples", NULL);
+      system_example_path = g_build_filename (get_data_dir (), "..", "examples", "denemo", NULL);
       GDir *denemo_path = g_dir_open(system_example_path, 0, NULL);
       if(denemo_path == NULL) {
 	warningdialog ("No examples directory in installation");
