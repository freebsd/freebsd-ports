--- src/gtk/options_dialog.c.orig	Sat Feb  5 16:42:53 2005
+++ src/gtk/options_dialog.c	Sat Feb  5 16:45:15 2005
@@ -1002,7 +1002,7 @@
   gtk_widget_show (box);
   
 #if GTK_MAJOR_VERSION == 1
-  tempwid = gtk_label_new (_("Type:"))
+  tempwid = gtk_label_new (_("Type:"));
 #else
   tempwid = gtk_label_new_with_mnemonic (_("_Type:"));
 #endif
