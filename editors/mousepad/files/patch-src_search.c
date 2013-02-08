--- src/search.c.orig
+++ src/search.c
@@ -210,8 +210,11 @@
 		G_CALLBACK(toggle_sensitivity), NULL);
 	 g_signal_connect(G_OBJECT(entry_find), "delete-text",
 		G_CALLBACK(toggle_sensitivity), NULL);
-	 if (sd->search.string_find) 
+	 if (sd->search.string_find) {
 		 gtk_entry_set_text(GTK_ENTRY(entry_find), sd->search.string_find);
+		 gtk_dialog_set_response_sensitive(GTK_DIALOG(dialog),
+			GTK_RESPONSE_OK, TRUE);
+	 }
 
 	gtk_dialog_set_default_response(GTK_DIALOG(dialog), GTK_RESPONSE_OK);
 	gtk_entry_set_activates_default(GTK_ENTRY(entry_find), TRUE);
@@ -275,8 +278,11 @@
 		G_CALLBACK(toggle_sensitivity), NULL);
 	 g_signal_connect(G_OBJECT(entry_find), "delete-text",
 		G_CALLBACK(toggle_sensitivity), NULL);
-	 if (sd->search.string_find) 
+	 if (sd->search.string_find) {
 		 gtk_entry_set_text(GTK_ENTRY(entry_find), sd->search.string_find);
+		 gtk_dialog_set_response_sensitive(GTK_DIALOG(dialog),
+			GTK_RESPONSE_OK, TRUE);
+	}
 	label_replace = gtk_label_new_with_mnemonic(_("Re_place with: "));
 	 gtk_misc_set_alignment(GTK_MISC(label_replace), 0, 0.5);
 	 gtk_table_attach_defaults(GTK_TABLE(table), label_replace, 0, 1, 1, 2);
