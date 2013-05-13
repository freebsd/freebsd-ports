Index: src/callbacks.c
@@ -336,7 +336,7 @@
       gint rate;
       gboolean backup;
       GtkFileFilter* filefilter;
-      G_CONST_RETURN gchar *filter;
+      const gchar *filter;
       
       filefilter = gtk_file_chooser_get_filter(GTK_FILE_CHOOSER (chooser));
       filter     = gtk_file_filter_get_name(filefilter);
