--- src/exif_view.c.orig        Tue Feb  1 13:20:55 2005
+++ src/exif_view.c     Tue Feb  1 13:20:16 2005
@@ -87,6 +87,7 @@
                                  ExifContent *content)
 {
    const gchar *text[2];
+   gchar value[1024];
    gint i;

    g_return_if_fail (clist);
@@ -104,7 +105,7 @@
    for (i = 0; i < content->count; i++) {
       text[0] = exif_tag_get_name (content->entries[i]->tag);
       if (text[0] && *text[0]) text[0] = _(text[0]);
-      text[1] = exif_entry_get_value (content->entries[i]);
+      text[1] = exif_entry_get_value (content->entries[i], value, sizeof(value));
       if (text[1] && *text[1]) text[1] = _(text[1]);
 #ifdef ENABLE_TREEVIEW
       {
