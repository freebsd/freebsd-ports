--- schematic/src/x_tabs.c.orig	2019-10-03 20:45:55 UTC
+++ schematic/src/x_tabs.c
@@ -53,7 +53,7 @@
  * key:         use-tabs
  * group:       schematic.gui
  * type:        boolean
- * default val: false
+ * default val: true
  *
  * 2) Whether to show "close" button on tabs:
  * key:         show-close-button
@@ -75,7 +75,7 @@
 
 
 static gboolean
-g_x_tabs_enabled = FALSE;
+g_x_tabs_enabled = TRUE;
 
 static gboolean
 g_x_tabs_show_close_button = TRUE;
@@ -284,6 +284,28 @@ x_tabs_page_on_sel (GtkNotebook* nbook,
                     guint        ndx,
                     gpointer     data);
 
+static void
+x_tabs_page_on_reordered (GtkNotebook* nbook,
+                          GtkWidget*   wtab,
+                          guint        newindex,
+                          gpointer     data);
+
+
+static gboolean
+x_tabs_hdr_on_mouse_click (GtkWidget* hdr, GdkEvent* e, gpointer data);
+static GtkMenu*
+x_tabs_menu_create (TabInfo* nfo);
+static void
+x_tabs_menu_create_item (GschemToplevel* toplevel,
+                         GtkWidget*      menu,
+                         const gchar*    action_name,
+                         const gchar*    action_label,
+                         const gchar*    icon_name);
+static void
+x_tabs_menu_create_item_separ (GtkWidget* menu);
+static void
+x_tabs_menu_item_on_activate (GtkAction* action, gpointer data);
+
 
 
 /* page view: */
@@ -409,7 +431,24 @@ x_tabs_dbg_pages_dump (GschemToplevel* w
   printf( " ^^^^^^^^^^^^^^ pages ^^^^^^^^^^^^^^^^^^\n\n" );
 }
 
-#endif
+static void
+x_tabs_dbg_pages_dump_simple (GschemToplevel* w_current)
+{
+  printf( " >> pages:\n" );
+  g_return_if_fail( w_current != NULL );
+
+  for ( GList* node = w_current->toplevel->pages->glist;
+        node != NULL;
+        node = g_list_next( node ) )
+  {
+    PAGE* p = node->data;
+    printf( "    p: [%s]\n", g_path_get_basename( s_page_get_filename(p) ) );
+  }
+
+  printf( "\n" );
+}
+
+#endif /* DEBUG */
 
 
 
@@ -661,6 +700,11 @@ x_tabs_nbook_create (GschemToplevel* w_c
   g_signal_connect (nbook, "switch-page",
                     G_CALLBACK (&x_tabs_page_on_sel), w_current);
 
+  g_signal_connect (nbook,
+                    "page-reordered",
+                    G_CALLBACK (&x_tabs_page_on_reordered),
+                    w_current);
+
 } /* x_tabs_nbook_create() */
 
 
@@ -913,7 +957,18 @@ x_tabs_hdr_set (GtkNotebook* nbook, TabI
   g_return_if_fail (nfo != NULL);
 
   GtkWidget* hdr = x_tabs_hdr_create (nfo);
-  gtk_notebook_set_tab_label (nbook, nfo->wtab_, hdr);
+
+  GtkWidget* ebox = gtk_event_box_new();
+  gtk_event_box_set_visible_window (GTK_EVENT_BOX (ebox), FALSE);
+  gtk_container_add (GTK_CONTAINER (ebox), hdr);
+  gtk_widget_show_all (ebox);
+
+  g_signal_connect (ebox,
+                    "button-press-event",
+                    G_CALLBACK (&x_tabs_hdr_on_mouse_click),
+                    nfo);
+
+  gtk_notebook_set_tab_label (nbook, nfo->wtab_, ebox);
 }
 
 
@@ -1160,6 +1215,8 @@ x_tabs_page_new (GschemToplevel* w_curre
   x_tabs_tl_pview_cur_set (w_current, pview);
   gint ndx = x_tabs_nbook_page_add (w_current, page, pview, wtab);
 
+  gtk_notebook_set_tab_reorderable (w_current->xtabs_nbook, wtab, TRUE);
+
   return x_tabs_info_add (w_current, ndx, page, pview, wtab);
 
 } /* x_tabs_page_new() */
@@ -1485,3 +1542,158 @@ x_tabs_page_on_sel (GtkNotebook* nbook,
 
 } /* x_tabs_page_on_sel() */
 
+
+
+/*! \brief GtkNotebook "page-reordered" signal handler.
+ */
+static void
+x_tabs_page_on_reordered (GtkNotebook* nbook,
+                          GtkWidget*   wtab,
+                          guint        newindex,
+                          gpointer     data)
+{
+  GschemToplevel* w_current = (GschemToplevel*) data;
+  g_return_if_fail (w_current != NULL);
+  g_return_if_fail (w_current->toplevel != NULL);
+  g_return_if_fail (w_current->toplevel->pages != NULL);
+
+  TabInfo* nfo = x_tabs_info_find_by_wtab (w_current->xtabs_info_list, wtab);
+  g_return_if_fail (nfo != NULL);
+
+  GedaPageList* pages = w_current->toplevel->pages;
+  geda_list_move_item (pages, nfo->page_, newindex);
+
+  gtk_widget_grab_focus (GTK_WIDGET (nfo->pview_));
+  page_select_widget_update (w_current);
+
+#ifdef DEBUG
+  x_tabs_dbg_pages_dump_simple( w_current );
+#endif
+
+} /* x_tabs_page_on_reordered() */
+
+
+
+/*! \brief Create popup menu for tab's header.
+ */
+static GtkMenu*
+x_tabs_menu_create (TabInfo* nfo)
+{
+  g_return_val_if_fail (nfo != NULL, NULL);
+
+  GschemToplevel* tl = nfo->tl_;
+  g_return_val_if_fail (tl != NULL, NULL);
+
+  GtkWidget* menu = gtk_menu_new();
+  x_tabs_menu_create_item (tl, menu, "file-new", _("_New"), GTK_STOCK_NEW);
+  x_tabs_menu_create_item (tl, menu, "file-open", _("_Open"), GTK_STOCK_OPEN);
+  x_tabs_menu_create_item_separ (menu);
+  x_tabs_menu_create_item (tl, menu, "file-save", _("_Save"), GTK_STOCK_SAVE);
+  x_tabs_menu_create_item (tl, menu, "file-save-as", _("Save _As..."), GTK_STOCK_SAVE_AS);
+  x_tabs_menu_create_item_separ (menu);
+  x_tabs_menu_create_item (tl, menu, "page-manager", _("Page _Manager..."), NULL);
+  x_tabs_menu_create_item_separ (menu);
+  x_tabs_menu_create_item (tl, menu, "page-close", _("_Close"), GTK_STOCK_CLOSE);
+
+  gtk_widget_show_all (menu);
+  return GTK_MENU (menu);
+
+} /* x_tabs_menu_create() */
+
+
+
+/*! \brief Tab's header widget "button-press-event" signal handler.
+ *  \todo  Consider switching to clicked tab
+ */
+static gboolean
+x_tabs_hdr_on_mouse_click (GtkWidget* hdr, GdkEvent* e, gpointer data)
+{
+  g_return_val_if_fail (data != NULL, FALSE);
+  GdkEventButton* ebtn = (GdkEventButton*) e;
+
+  TabInfo* nfo    = (TabInfo*) data;
+  TabInfo* nfocur = x_tabs_info_cur (nfo->tl_);
+
+  /* show menu for current tab only:
+  */
+  if (nfo != nfocur)
+    return FALSE;
+
+#ifdef DEBUG
+  printf( "p: [%s]\n",   g_path_get_basename( s_page_get_filename(nfo->page_) ) );
+  printf( "C: [%s]\n\n", g_path_get_basename( s_page_get_filename(nfocur->page_) ) );
+#endif
+
+  if (ebtn->type == GDK_BUTTON_PRESS && ebtn->button == 3)
+  {
+    GtkMenu* menu = x_tabs_menu_create (nfo);
+
+    int btn = 0;
+    int etime = 0;
+    if (ebtn != NULL)
+    {
+      btn = ebtn->button;
+      etime = gtk_get_current_event_time();
+    }
+
+    gtk_menu_attach_to_widget (menu, hdr, NULL);
+    gtk_menu_popup (menu, NULL, NULL, NULL, NULL, btn, etime);
+
+    return TRUE;
+  }
+
+  return FALSE;
+
+} /* x_tabs_page_on_mouse_click() */
+
+
+
+/*! \brief "activate" signal handler for context menu item action.
+ */
+static void
+x_tabs_menu_item_on_activate (GtkAction* action, gpointer data)
+{
+  GschemToplevel* toplevel    = (GschemToplevel*) data;
+  const gchar*    action_name = gtk_action_get_name (action);
+
+  g_action_eval_by_name (toplevel, action_name);
+}
+
+
+
+/*! \brief Create and add popup menu item separator.
+ */
+static void
+x_tabs_menu_create_item_separ (GtkWidget* menu)
+{
+  gtk_menu_shell_append (GTK_MENU_SHELL (menu),
+                         gtk_separator_menu_item_new());
+}
+
+
+
+/*! \brief Create and add popup menu item.
+ */
+static void
+x_tabs_menu_create_item (GschemToplevel* toplevel,
+                         GtkWidget*      menu,
+                         const gchar*    action_name,
+                         const gchar*    action_label,
+                         const gchar*    icon_name)
+{
+  GschemAction* action = gschem_action_new (action_name,  /* name */
+                                            action_label, /* label */
+                                            NULL,         /* tooltip */
+                                            icon_name,    /* stock_id */
+                                            NULL);        /* multikey_accel */
+
+  GtkWidget* item = gtk_action_create_menu_item (GTK_ACTION (action));
+  gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
+
+  g_signal_connect (action,
+                    "activate",
+                    G_CALLBACK (&x_tabs_menu_item_on_activate),
+                    toplevel);
+
+} /* x_tabs_menu_create_item() */
+
