--- src/gmdb2/gmdb.h.orig	Mon Jan 13 04:59:42 2003
+++ src/gmdb2/gmdb.h	Mon Mar  6 11:32:10 2006
@@ -44,6 +44,10 @@
 void gmdb_debug_tab_new(GtkWidget *notebook);
 void gmdb_debug_new_cb(GtkWidget *w, gpointer *data);
 
+void gmdb_table_export_populate_dialog(GladeXML *xml);
+void gmdb_sql_save_query(GladeXML *xml, gchar *file_path);
+void gmdb_sql_save_as_cb(GtkWidget *w, GladeXML *xml);
+
 unsigned long gmdb_prefs_get_maxrows();
 
 extern GtkWidget *gmdb_prefs_new();
