--- src/ui/ui-main.c.orig	Fri Jan 16 20:28:27 2004
+++ src/ui/ui-main.c	Fri Jan 16 20:28:45 2004
@@ -587,6 +587,7 @@
 			       const char *message_format, ...) {
     char *message;
     va_list args;
+    GtkWidget *dialog;
     
     if (message_format)	{
 	va_start (args, message_format);
@@ -596,7 +597,6 @@
 	message = NULL;
     }
     
-    GtkWidget *dialog;
     dialog = gtk_message_dialog_new (transient_parent,
 				     GTK_DIALOG_DESTROY_WITH_PARENT,
 				     GTK_MESSAGE_ERROR,
