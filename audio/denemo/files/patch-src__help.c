--- src/help.c.orig
+++ src/help.c
@@ -63,7 +63,7 @@
   GError *error = NULL;
 
   /* get the uri to the manual */
-  gchar *manualpath = g_build_filename (get_data_dir (), "manual",
+  gchar *manualpath = g_build_filename (get_data_dir (), "..", "doc", "denemo", "manual",
                                         "denemo-manual.html", NULL);
   gchar *manualuri =  url?g_strdup(url):g_filename_to_uri (manualpath, NULL, NULL);
 
