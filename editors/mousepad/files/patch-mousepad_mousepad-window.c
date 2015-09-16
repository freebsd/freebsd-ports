--- mousepad/mousepad-window.c.orig	2014-09-01 20:58:02 UTC
+++ mousepad/mousepad-window.c
@@ -717,12 +717,13 @@ mousepad_window_action_group_style_schem
                                                    MousepadActionGroup *group)
 {
   GtkSourceStyleScheme *scheme;
-  const gchar          *scheme_id;
+  const gchar          *scheme_id = NULL;
   gint                  npages, i;
 
   /* get the new active language */
   scheme = mousepad_action_group_get_active_style_scheme (group);
-  scheme_id = gtk_source_style_scheme_get_id (scheme);
+  if (scheme != NULL)
+    scheme_id = gtk_source_style_scheme_get_id (scheme);
 
   /* update the color scheme on all the documents */
   npages = gtk_notebook_get_n_pages (GTK_NOTEBOOK (window->notebook));
