--- src/gtkutils.c.orig	2003-05-26 13:34:38 UTC
+++ src/gtkutils.c
@@ -112,14 +112,14 @@ GtkWidget *ut_spin_button_start_new(gcha
 
 /* shows simple message box */
 void ut_simple_message_box(gchar *message) {
-  	GtkWidget *dialog = gtk_message_dialog_new(NULL, 0, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, message);
+  	GtkWidget *dialog = gtk_message_dialog_new(NULL, 0, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "%s", message);
  	gtk_dialog_run(GTK_DIALOG(dialog));
  	gtk_widget_destroy(dialog);
 }
 
 /* shows simple message box */
 void ut_simple_message_box_with_title(gchar *message, gchar *title) {
-  	GtkWidget *dialog = gtk_message_dialog_new(NULL, 0, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, message);
+  	GtkWidget *dialog = gtk_message_dialog_new(NULL, 0, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "%s", message);
   	gtk_window_set_title(GTK_WINDOW(dialog), title);
  	gtk_dialog_run(GTK_DIALOG(dialog));
  	gtk_widget_destroy(dialog);
