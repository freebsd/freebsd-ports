--- gnome-screenshot/screenshot-save.c.orig	Mon Nov  1 15:56:19 2004
+++ gnome-screenshot/screenshot-save.c	Fri Dec 17 23:11:51 2004
@@ -94,16 +94,20 @@
       gchar *message = NULL;
       gchar *error_message = NULL;
       GtkWidget *dialog;
+      GIOStatus status;
 
-      g_io_channel_read_line (source, &error_message, NULL, NULL, NULL);
-      message = g_strdup_printf ("Unable to save the screenshot to disk:\n\n%s", error_message);
-      dialog = gtk_message_dialog_new (NULL, 0,
+      status = g_io_channel_read_line (source, &error_message, NULL, NULL, NULL);
+      if (status == G_IO_STATUS_NORMAL)
+        {
+          message = g_strdup_printf ("Unable to save the screenshot to disk:\n\n%s", error_message);
+          dialog = gtk_message_dialog_new (NULL, 0,
 				       GTK_MESSAGE_ERROR,
 				       GTK_BUTTONS_OK,
 				       message);
-      gtk_dialog_run (GTK_DIALOG (dialog));
-      gtk_widget_destroy (dialog);
-      exit (1);
+          gtk_dialog_run (GTK_DIALOG (dialog));
+          gtk_widget_destroy (dialog);
+          exit (1);
+	}
     }
 
   (*save_callback) (save_user_data);
