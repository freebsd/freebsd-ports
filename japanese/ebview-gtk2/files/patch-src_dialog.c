--- src/dialog.c.orig	2014-10-01 16:47:22.168412743 +0200
+++ src/dialog.c	2014-10-01 16:47:46.245411370 +0200
@@ -25,7 +25,7 @@
 #include "statusbar.h"
 
 gboolean active=FALSE;
-static gchar g_message[1024];
+static gchar _g_message[1024];
 
 void center_dialog(GtkWidget *window, GtkWidget *dialog){
 	gint window_x, window_y;
@@ -69,7 +69,7 @@
 					GTK_DIALOG_DESTROY_WITH_PARENT /* | GTK_DIALOG_NO_SEPARATOR */,
 					GTK_MESSAGE_WARNING,
 					GTK_BUTTONS_OK,
-					g_message);
+					_g_message);
 	gtk_dialog_run(GTK_DIALOG(dialog));
 	gtk_widget_destroy(dialog);
 	active  = FALSE;
@@ -98,7 +98,7 @@
 					GTK_DIALOG_DESTROY_WITH_PARENT /* | GTK_DIALOG_NO_SEPARATOR */,
 					GTK_MESSAGE_ERROR,
 					GTK_BUTTONS_CLOSE,
-					g_message);
+					_g_message);
 					
 	gtk_dialog_run(GTK_DIALOG(dialog));
 	gtk_widget_destroy(dialog);
@@ -114,7 +114,7 @@
 	LOG(LOG_DEBUG, "IN : popup_warning");
 
 	g_idle_add(idle_warning, (gpointer)message);
-	strcpy(g_message, message);
+	strcpy(_g_message, message);
 
 	LOG(LOG_DEBUG, "OUT : popup_warning");
 }
@@ -123,7 +123,7 @@
 
 	LOG(LOG_DEBUG, "IN : popup_error");
 
-	strcpy(g_message, message);
+	strcpy(_g_message, message);
 
 	g_idle_add(idle_error, (gpointer)message);
 
