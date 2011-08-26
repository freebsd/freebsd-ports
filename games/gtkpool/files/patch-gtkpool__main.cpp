--- gtkpool/main.cpp.orig	2002-08-06 02:36:10.000000000 +0900
+++ gtkpool/main.cpp	2011-08-19 04:36:56.000000000 +0900
@@ -162,10 +162,10 @@
 	gtk_widget_show(button);*/
 
 	//setup chat box for multiplayer
-	app.chat_text = gtk_text_new((GtkAdjustment *)NULL, (GtkAdjustment *)NULL);
+	app.chat_text = gtk_text_view_new();
 	gtk_widget_set_usize(app.chat_text, -2, 60);
-	gtk_text_set_editable(GTK_TEXT(app.chat_text), FALSE);
-	gtk_text_set_word_wrap(GTK_TEXT(app.chat_text), TRUE);
+	gtk_text_view_set_editable(GTK_TEXT_VIEW(app.chat_text), FALSE);
+	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(app.chat_text), GTK_WRAP_WORD);
 	gtk_widget_set_events (app.chat_text, GDK_NOTHING);
 //	networking not ready for this version
 
