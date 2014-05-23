--- src/ui/help.c.orig
+++ src/ui/help.c
@@ -57,7 +57,7 @@
   GError *error = NULL;
 
   /* get the uri to the manual */
-  gchar *manualpath = g_build_filename (get_system_data_dir (), "manual",
+  gchar *manualpath = g_build_filename (get_system_data_dir (), "..", "doc", "denemo", "manual",
                                         "denemo-manual.html", NULL);
   gchar *manualuri = url ? g_strdup (url) : g_filename_to_uri (manualpath, NULL, NULL);
 
