--- src/bar_exif.h.orig	2019-08-20 19:01:23 UTC
+++ src/bar_exif.h
@@ -29,8 +29,8 @@ void bar_pane_exif_entry_add_from_config(GtkWidget *pa
 
 /* these are exposed for when duplication of the exif bar's text is needed */
 
-const gchar **bar_exif_key_list;
-const gint bar_exif_key_count;
+extern const gchar **bar_exif_key_list;
+extern const gint bar_exif_key_count;
 GList *bar_pane_exif_list();
 
 #endif
