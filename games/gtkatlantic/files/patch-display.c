--- src/display.c.orig	Fri Jun 25 03:02:45 2004
+++ src/display.c	Thu Mar 17 19:41:54 2005
@@ -201,6 +201,8 @@
 
 
 void display_text(guchar *message) {
+        GtkTextIter txtiter;
+        GtkTextBuffer *txtbuff;
 
 	GtkWidget *vbox;
 	GtkWidget *text;
@@ -240,7 +242,7 @@
 	msg = g_strdup("");
 
 	for(len = strlen(data), i = 0 ; i < len ; i++)  {
-
+        	
 		chr = g_strndup(data +i, 1);
 
 		if(! strncmp(data +i, "&amp;", 5) ) {
@@ -256,9 +258,6 @@
 	}
 	g_free(data);
 
-	/* fill with text */
-	GtkTextBuffer *txtbuff;
-	GtkTextIter txtiter;
 	
 	txtbuff = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text));
 	gtk_text_buffer_get_end_iter(txtbuff, &txtiter);
