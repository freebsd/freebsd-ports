--- src/dialogs/stroke-style.c.orig	Thu Dec 11 08:05:58 2003
+++ src/dialogs/stroke-style.c	Thu Dec 11 08:08:22 2003
@@ -581,6 +581,7 @@
 	GtkWidget *spw, *f, *t, *l, *hb, *sb, *us, *tb, *ds;
 	GtkObject *a;
 	gint i;
+	SPDesktop *desktop;
 
 	spw = sp_widget_new_global (INKSCAPE);
 
@@ -725,7 +726,7 @@
 	gtk_signal_connect (GTK_OBJECT (spw), "change_selection", GTK_SIGNAL_FUNC (sp_stroke_style_line_change_selection), NULL);
 	gtk_signal_connect (GTK_OBJECT (spw), "attr_changed", GTK_SIGNAL_FUNC (sp_stroke_style_line_attr_changed), NULL);
 
-	SPDesktop *desktop = inkscape_active_desktop();
+	desktop = inkscape_active_desktop();
 	sp_stroke_style_line_update (SP_WIDGET (spw), desktop ? SP_DT_SELECTION (desktop) : NULL);
 	// sp_stroke_style_line_update (SP_WIDGET (spw), SP_ACTIVE_DESKTOP ? SP_DT_SELECTION (SP_ACTIVE_DESKTOP) : NULL);
 
