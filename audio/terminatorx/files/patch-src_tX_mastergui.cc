--- src/tX_mastergui.cc.orig	2011-01-31 06:01:32.000000000 +0900
+++ src/tX_mastergui.cc	2011-03-24 11:38:00.000000000 +0900
@@ -273,7 +273,7 @@
 GtkSignalFunc new_tables() {
 	GtkWidget *dialog=gtk_message_dialog_new(GTK_WINDOW(main_window), 
 		GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_QUESTION, GTK_BUTTONS_YES_NO,
-		"Are you sure you want to loose all turntables and events?");
+		"Are you sure you want to lose all turntables and events?");
 	
 	int res=gtk_dialog_run(GTK_DIALOG(dialog));
 	gtk_widget_destroy(dialog);
@@ -894,7 +894,7 @@
 	if (globals.quit_confirm) {
 		GtkWidget *dialog=gtk_message_dialog_new(GTK_WINDOW(main_window), 
 		GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_QUESTION, GTK_BUTTONS_YES_NO,
-		"Exit terminatorX and loose all unsaved data?");
+		"Exit terminatorX and lose all unsaved data?");
 		
 		int res=gtk_dialog_run(GTK_DIALOG(dialog));
 		gtk_widget_destroy(dialog);
