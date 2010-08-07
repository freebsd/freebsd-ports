--- src/callbacks.c.orig	2010-06-21 22:33:40.000000000 +0200
+++ src/callbacks.c	2010-06-21 22:38:00.000000000 +0200
@@ -9,6 +9,9 @@
 #include "interface.h"
 #include "support.h"
 
+/* missing headers on original file */
+#include <string.h>
+#include <glib/gprintf.h>
 
 GtkWidget        *savedialog;
 gchar            *colorname;
@@ -166,9 +169,10 @@
 void on_copy_color_to_clipboard_activate (GtkMenuItem *menuitem, gpointer user_data)
 {
 	gchar* hex;
+	GtkClipboard *cb;
 	
 	hex = hex_value (colorvalue);
-	GtkClipboard *cb = gtk_clipboard_get (gdk_atom_intern ("PRIMARY", FALSE));
+	cb = gtk_clipboard_get (gdk_atom_intern ("PRIMARY", FALSE));
 	gtk_clipboard_set_text (cb, hex, strlen (hex));
 }
 
