
$FreeBSD$

--- src/callbacks.c.orig
+++ src/callbacks.c
@@ -166,9 +166,10 @@
 void on_copy_color_to_clipboard_activate (GtkMenuItem *menuitem, gpointer user_data)
 {
 	gchar* hex;
+	GtkClipboard *cb;
 	
 	hex = hex_value (colorvalue);
-	GtkClipboard *cb = gtk_clipboard_get (gdk_atom_intern ("PRIMARY", FALSE));
+	cb = gtk_clipboard_get (gdk_atom_intern ("PRIMARY", FALSE));
 	gtk_clipboard_set_text (cb, hex, strlen (hex));
 }
 
