--- src/start-with.c.orig	Sat Nov  8 05:55:08 2003
+++ src/start-with.c	Sat Nov  8 05:55:51 2003
@@ -54,9 +54,11 @@
 on_open_last_project_clicked (GtkButton *button, gpointer data)
 {
 	GtkWidget *dialog = GTK_WIDGET (data);	
+	gchar* prj_filename;
+
 	/*  Do not allow a second click  */
 	gtk_widget_set_sensitive (GTK_WIDGET (button), FALSE);
-	gchar *prj_filename = anjuta_preferences_get (app->preferences,
+	prj_filename = anjuta_preferences_get (app->preferences,
 												  "anjuta.last.open.project");
 	project_dbase_load_project (app->project_dbase, prj_filename, TRUE);
 	g_free (prj_filename);
