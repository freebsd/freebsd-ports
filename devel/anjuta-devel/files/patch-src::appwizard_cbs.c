--- src/appwizard_cbs.c.orig	Sat Nov  8 05:35:15 2003
+++ src/appwizard_cbs.c	Sat Nov  8 05:35:41 2003
@@ -235,10 +235,10 @@
 			    gnomedruidpage, gpointer arg1, gpointer user_data)
 {
 	AppWizard *aw;
-	aw = user_data;
 	GtkTextBuffer *buffer;
 	GtkTextIter start, end;
 	
+	aw = user_data;
 	g_free (aw->description);
 	buffer =
 		gtk_text_view_get_buffer (GTK_TEXT_VIEW (aw->widgets.description_text));
