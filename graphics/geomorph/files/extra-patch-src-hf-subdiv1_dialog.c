--- src/hf/subdiv1_dialog.c.orig	Thu Apr  7 05:34:56 2005
+++ src/hf/subdiv1_dialog.c	Mon Mar  6 12:55:02 2006
@@ -55,9 +55,9 @@
 }
 
 gint change_subdiv1_seed(GtkWidget *entry, gpointer data) {
+	unsigned int s;
 	hf_wrapper_struct *hfw;
 	hfw = (hf_wrapper_struct *) * (hf_wrapper_struct **) data;
-	unsigned int s;
 	// Avoid double display... the callback seems always to be called twice,
 	// the first time with an empty entry, I don't know why
 	// (maybe because "gtk_entry_set_text" blanks the field before writing in it??)
