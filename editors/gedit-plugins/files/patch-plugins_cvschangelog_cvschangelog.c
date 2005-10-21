--- plugins/cvschangelog/cvschangelog.c.orig	Sat Aug 23 19:31:01 2003
+++ plugins/cvschangelog/cvschangelog.c	Fri Oct 21 14:20:50 2005
@@ -163,6 +163,16 @@
 	return FALSE;
 }
 
+static char *
+document_get_chars (GeditDocument *doc)
+{
+	GtkTextIter start_iter;
+	GtkTextIter end_iter;
+
+	gtk_text_buffer_get_bounds (GTK_TEXT_BUFFER (doc), &start_iter, &end_iter);
+	return gtk_text_buffer_get_text (GTK_TEXT_BUFFER (doc), &start_iter, &end_iter, TRUE);
+}
+
 static void
 cvs_changelogs_cb (BonoboUIComponent *uic, gpointer user_data, const gchar *verbname)
 {
@@ -178,7 +188,7 @@
 
 	doc = gedit_view_get_document (view);
 
-	buf = gedit_document_get_chars (doc, 0, -1);
+	buf = document_get_chars (doc);
 
 	list = get_changelogs (buf);
 
@@ -209,7 +219,7 @@
 	doc = gedit_get_active_document ();
 
 	if (doc != NULL) {	 	
-		buf = gedit_document_get_chars (doc, 0, -1);
+		buf = document_get_chars (doc);
 
 		if (is_commit_message (buf))
 			gedit_menus_set_verb_sensitive (uic,
