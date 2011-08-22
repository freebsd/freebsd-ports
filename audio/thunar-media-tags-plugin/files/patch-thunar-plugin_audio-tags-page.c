--- thunar-plugin/audio-tags-page.c.orig	2006-09-11 11:40:56.000000000 +0200
+++ thunar-plugin/audio-tags-page.c	2011-05-15 19:44:12.000000000 +0200
@@ -90,7 +90,6 @@
   ThunarxPropertyPage __parent__;
 
   /* Widgets */
-  GtkTooltips     *tooltips;
   GtkWidget       *table;
   GtkWidget       *save_button;
   GtkWidget       *info_button;
@@ -282,10 +281,6 @@
 
   gtk_container_set_border_width (GTK_CONTAINER (page), 8);
 
-  /* Allocate the shared tooltips */
-  page->tooltips = gtk_tooltips_new ();
-  exo_gtk_object_ref_sink (GTK_OBJECT (page->tooltips));
-
   /* Main container */
   vbox = gtk_vbox_new (FALSE, 8);
   gtk_container_add (GTK_CONTAINER (page), vbox);
@@ -317,7 +312,8 @@
   /* Track spin button */
   spin = gtk_spin_button_new (GTK_ADJUSTMENT (adjustment), 1, 0);
   exo_mutual_binding_new (G_OBJECT (adjustment), "value", G_OBJECT (page), "track");
-  gtk_tooltips_set_tip (page->tooltips, spin, _("Enter the track number here."), NULL);
+  gtk_widget_set_tooltip_text (GTK_WIDGET (spin), _("Enter the track number here."));
+
   gtk_container_add (GTK_CONTAINER (alignment), spin);
   gtk_label_set_mnemonic_widget (GTK_LABEL (label), spin);
   gtk_widget_show (spin);
@@ -340,7 +336,7 @@
   /* Year spin button */
   spin = gtk_spin_button_new (GTK_ADJUSTMENT (adjustment), 1, 0);
   exo_mutual_binding_new (G_OBJECT (adjustment), "value", G_OBJECT (page), "year");
-  gtk_tooltips_set_tip (page->tooltips, spin, _("Enter the release year here."), NULL);
+  gtk_widget_set_tooltip_text (GTK_WIDGET (spin), _("Enter the release year here."));
   gtk_container_add (GTK_CONTAINER (alignment), spin);
   gtk_label_set_mnemonic_widget (GTK_LABEL (label), spin);
   gtk_widget_show (spin);
@@ -355,7 +351,7 @@
   /* Artist entry */
   entry = gtk_entry_new ();
   exo_mutual_binding_new (G_OBJECT (entry), "text", G_OBJECT (page), "artist");
-  gtk_tooltips_set_tip (page->tooltips, entry, _("Enter the name of the artist or author of this file here."), NULL);
+  gtk_widget_set_tooltip_text (GTK_WIDGET (entry), _("Enter the name of the artist or author of this file here."));
   gtk_table_attach (GTK_TABLE (page->table), entry, 1, 4, 1, 2, GTK_EXPAND | GTK_FILL, 0, 0, 0);
   gtk_label_set_mnemonic_widget (GTK_LABEL (label), entry);
   gtk_widget_show (entry);
@@ -370,7 +366,7 @@
   /* Title entry */
   entry = gtk_entry_new ();
   exo_mutual_binding_new (G_OBJECT (entry), "text", G_OBJECT (page), "title");
-  gtk_tooltips_set_tip (page->tooltips, entry, _("Enter the song title here."), NULL);
+  gtk_widget_set_tooltip_text (GTK_WIDGET (entry), _("Enter the song title here."));
   gtk_table_attach (GTK_TABLE (page->table), entry, 1, 4, 2, 3, GTK_EXPAND | GTK_FILL, 0, 0, 0);
   gtk_widget_show (entry);
 
@@ -384,7 +380,7 @@
   /* Album entry */
   entry = gtk_entry_new ();
   exo_mutual_binding_new (G_OBJECT (entry), "text", G_OBJECT (page), "album");
-  gtk_tooltips_set_tip (page->tooltips, entry, _("Enter the album/record title here."), NULL);
+  gtk_widget_set_tooltip_text (GTK_WIDGET (entry), _("Enter the album/record title here."));
   gtk_table_attach (GTK_TABLE (page->table), entry, 1, 4, 3, 4, GTK_EXPAND | GTK_FILL, 0, 0, 0);
   gtk_widget_show (entry);
   
@@ -398,7 +394,7 @@
   /* Comment entry */
   entry = gtk_entry_new ();
   exo_mutual_binding_new (G_OBJECT (entry), "text", G_OBJECT (page), "comment");
-  gtk_tooltips_set_tip (page->tooltips, entry, _("Enter your comments here."), NULL);
+  gtk_widget_set_tooltip_text (GTK_WIDGET (entry), _("Enter your comments here."));
   gtk_table_attach (GTK_TABLE (page->table), entry, 1, 4, 4, 5, GTK_EXPAND | GTK_FILL, 0, 0, 0);
   gtk_widget_show (entry);
 
@@ -412,7 +408,7 @@
   /* Genre combo box */
   combo = gtk_combo_box_entry_new_text ();
   exo_mutual_binding_new (G_OBJECT (GTK_BIN (combo)->child), "text", G_OBJECT (page), "genre");
-  gtk_tooltips_set_tip (page->tooltips, combo, _("Select or enter the genre of this song here."), NULL);
+  gtk_widget_set_tooltip_text (GTK_WIDGET (combo), _("Select or enter the genre of this song here."));
   gtk_table_attach (GTK_TABLE (page->table), combo, 1, 4, 5, 6, GTK_FILL, 0, 0, 0);
   gtk_widget_show (combo);
 
@@ -512,9 +508,6 @@
   if (G_LIKELY (page->genre != NULL))
     g_free (page->genre);
 
-  /* Release the tooltips */
-  g_object_unref (G_OBJECT (page->tooltips));
-
   (*G_OBJECT_CLASS (audio_tags_page_parent_class)->finalize) (object);
 }
 
