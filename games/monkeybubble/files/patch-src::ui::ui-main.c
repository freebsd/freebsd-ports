--- src/ui/ui-main.c.orig	Fri Aug 13 14:47:33 2004
+++ src/ui/ui-main.c	Fri Aug 13 14:48:06 2004
@@ -647,6 +647,7 @@
                                const char *message_format, ...) {
         char *message;
         va_list args;
+        GtkWidget *dialog;
     
         if (message_format)	{
                 va_start (args, message_format);
@@ -656,7 +657,6 @@
                 message = NULL;
         }
     
-        GtkWidget *dialog;
         dialog = gtk_message_dialog_new (transient_parent,
                                          GTK_DIALOG_DESTROY_WITH_PARENT,
                                          GTK_MESSAGE_ERROR,
