--- ggadget/gtk/utilities.cc.orig	2008-12-03 18:01:36.000000000 +1000
+++ ggadget/gtk/utilities.cc	2009-01-07 00:52:52.000000000 +1000
@@ -83,7 +83,7 @@
                                     "%s", message);
     gtk_dialog_add_buttons(GTK_DIALOG(dialog), GTK_STOCK_NO, GTK_RESPONSE_NO,
                            GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
-                           GTK_STOCK_YES, GTK_RESPONSE_YES, NULL);
+                           GTK_STOCK_YES, GTK_RESPONSE_YES, (const gchar*)0);
     gtk_dialog_set_default_response(GTK_DIALOG(dialog), GTK_RESPONSE_YES);
   } else {
     dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL,
