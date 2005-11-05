--- gucharmap/gucharmap-window.c.orig	Mon Jan 24 05:56:53 2005
+++ gucharmap/gucharmap-window.c	Sat Sep 17 04:04:07 2005
@@ -82,6 +82,8 @@
   ChaptersMode chapters_mode; 
 };
 
+static GtkWindowClass *parent_class = NULL;
+
 static void
 status_message (GtkWidget       *widget, 
                 const gchar     *message, 
@@ -417,8 +419,8 @@
     {
       GucharmapWindowPrivate *priv = GUCHARMAP_WINDOW_GET_PRIVATE (guw);
       gucharmap_charmap_set_chapters (guw->charmap, GUCHARMAP_CHAPTERS (gucharmap_script_chapters_new ()));
-      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->next_chapter_menu_item))), _("Next Script"));;
-      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->prev_chapter_menu_item))), _("Previous Script"));;
+      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->next_chapter_menu_item))), _("Next Script"));
+      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->prev_chapter_menu_item))), _("Previous Script"));
     }
 }
 
@@ -430,8 +432,8 @@
     {
       GucharmapWindowPrivate *priv = GUCHARMAP_WINDOW_GET_PRIVATE (guw);
       gucharmap_charmap_set_chapters (guw->charmap, GUCHARMAP_CHAPTERS (gucharmap_block_chapters_new ()));
-      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->next_chapter_menu_item))), _("Next Block"));;
-      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->prev_chapter_menu_item))), _("Previous Block"));;
+      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->next_chapter_menu_item))), _("Next Block"));
+      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->prev_chapter_menu_item))), _("Previous Block"));
     }
 }
 
@@ -834,12 +836,12 @@
   g_signal_connect (priv->status, "realize", G_CALLBACK (status_realize), guw);
 
   priv->progress = gtk_progress_bar_new ();
-  gtk_box_pack_start (GTK_BOX (hbox), priv->progress, FALSE, FALSE, 0);;
+  gtk_box_pack_start (GTK_BOX (hbox), priv->progress, FALSE, FALSE, 0);
 
 #if 0
   grip = gtk_statusbar_new ();
   gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR (grip), TRUE);
-  gtk_box_pack_start (GTK_BOX (hbox), grip, FALSE, FALSE, 0);;
+  gtk_box_pack_start (GTK_BOX (hbox), grip, FALSE, FALSE, 0);
 #endif
   gtk_widget_show_all (hbox);
 
@@ -886,11 +888,13 @@
     g_free (priv->last_search);
     */
 #endif
+  G_OBJECT_CLASS (parent_class)->finalize (object);
 }
 
 static void
 gucharmap_window_class_init (GucharmapWindowClass *clazz)
 {
+  parent_class = g_type_class_peek_parent (clazz);
   GTK_WIDGET_CLASS (clazz)->show_all = show_all;
   G_OBJECT_CLASS (clazz)->finalize = window_finalize;
   g_type_class_add_private (clazz, sizeof (GucharmapWindowPrivate));
