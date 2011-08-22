--- thunar-plugin/tag-renamer.c.orig	2006-06-17 21:10:05.000000000 +0200
+++ thunar-plugin/tag-renamer.c	2011-05-15 19:51:13.000000000 +0200
@@ -116,9 +116,6 @@
 {
   ThunarxRenamer __parent__;
 
-  /* Widgets */
-  GtkTooltips     *tooltips;
-
   /* Properties */
   TagRenamerFormat format;
   gboolean         replace_spaces;
@@ -209,10 +206,6 @@
   GEnumClass     *klass;
   gint            n;
 
-  /* Allocate shared tooltips */
-  tag_renamer->tooltips = gtk_tooltips_new ();
-  exo_gtk_object_ref_sink (GTK_OBJECT (tag_renamer->tooltips));
-
   table = gtk_table_new (2, 3, FALSE);
   gtk_table_set_row_spacings (GTK_TABLE (table), 6);
   gtk_table_set_col_spacings (GTK_TABLE (table), 12);
@@ -245,14 +238,14 @@
 
   button = gtk_check_button_new_with_mnemonic (_("_Underscores"));
   exo_mutual_binding_new (G_OBJECT (button), "active", G_OBJECT (tag_renamer), "replace-spaces");
-  gtk_tooltips_set_tip (tag_renamer->tooltips, button, _("Activating this option will replace all spaces in the target filename "
-        "with underscores."), NULL);
+  gtk_widget_set_tooltip_text (GTK_WIDGET (button), _("Activating this option will replace all spaces in the target filename "
+        "with underscores."));
   gtk_table_attach (GTK_TABLE (table), button, 2, 3, 0, 1, GTK_FILL, 0, 0, 0);
   gtk_widget_show (button);
 
   button = gtk_check_button_new_with_mnemonic (_("_Lowercase"));
   exo_mutual_binding_new (G_OBJECT (button), "active", G_OBJECT (tag_renamer), "lowercase");
-  gtk_tooltips_set_tip (tag_renamer->tooltips, button, _("If you activate this, the resulting filename will only contain lowercase letters."), NULL);
+  gtk_widget_set_tooltip_text (GTK_WIDGET (button), _("If you activate this, the resulting filename will only contain lowercase letters."));
   gtk_table_attach (GTK_TABLE (table), button, 2, 3, 1, 2, GTK_FILL, 0, 0, 0);
   gtk_widget_show (button);
 
@@ -272,9 +265,6 @@
 {
   TagRenamer *tag_renamer = TAG_RENAMER (object);
 
-  /* release the tooltips */
-  g_object_unref (G_OBJECT (tag_renamer->tooltips));
-
   /* Free strings */
   g_free (tag_renamer->artist);
   g_free (tag_renamer->title);
