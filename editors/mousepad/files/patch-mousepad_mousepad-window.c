--- mousepad/mousepad-window.c.orig	2014-09-01 20:58:02 UTC
+++ mousepad/mousepad-window.c
@@ -712,32 +712,6 @@ mousepad_window_create_languages_menu (MousepadWindow 
 
 
 static void
-mousepad_window_action_group_style_scheme_changed (MousepadWindow      *window,
-                                                   GParamSpec          *pspec,
-                                                   MousepadActionGroup *group)
-{
-  GtkSourceStyleScheme *scheme;
-  const gchar          *scheme_id;
-  gint                  npages, i;
-
-  /* get the new active language */
-  scheme = mousepad_action_group_get_active_style_scheme (group);
-  scheme_id = gtk_source_style_scheme_get_id (scheme);
-
-  /* update the color scheme on all the documents */
-  npages = gtk_notebook_get_n_pages (GTK_NOTEBOOK (window->notebook));
-  for (i = 0; i < npages; i++)
-    {
-      MousepadDocument *document;
-
-      document = MOUSEPAD_DOCUMENT (gtk_notebook_get_nth_page (GTK_NOTEBOOK (window->notebook), i));
-      mousepad_view_set_color_scheme (document->textview, scheme_id);
-    }
-}
-
-
-
-static void
 mousepad_window_create_style_schemes_menu (MousepadWindow *window)
 {
   GtkWidget           *menu, *item;
@@ -751,13 +725,6 @@ mousepad_window_create_style_schemes_menu (MousepadWin
   gtk_menu_item_set_submenu (GTK_MENU_ITEM (item), menu);
   gtk_widget_show_all (menu);
   gtk_widget_show (item);
-  
-  /* watch for activations of the style schemes actions */
-  g_signal_connect_object (window->action_group,
-                           "notify::active-style-scheme",
-                           G_CALLBACK (mousepad_window_action_group_style_scheme_changed),
-                           window,
-                           G_CONNECT_SWAPPED);
 }
 
 
@@ -2122,7 +2089,14 @@ mousepad_window_notebook_create_window (GtkNotebook   
       g_object_ref (G_OBJECT (document));
 
       /* remove the document from the active window */
+#if GTK_CHECK_VERSION (3, 16, 0)
+      gtk_notebook_detach_tab (GTK_CONTAINER (window->notebook), page);
+#else
+      /* crashes on GTK+ 3 somewhere between 3.10-3.16
+       * Fixed above using new function added in 3.16
+       * See: https://bugzilla.gnome.org/show_bug.cgi?id=744385 */
       gtk_container_remove (GTK_CONTAINER (window->notebook), page);
+#endif
 
       /* emit the new window with document signal */
       g_signal_emit (G_OBJECT (window), window_signals[NEW_WINDOW_WITH_DOCUMENT], 0, document, x, y);
