--- SciTEGTK.cxx.orig	Wed Apr  7 03:47:55 2004
+++ SciTEGTK.cxx	Wed Apr  7 03:48:14 2004
@@ -1232,7 +1232,9 @@
 	gtk_widget_show(comboDir);
 	gtk_entry_set_text(GTK_ENTRY(GTK_COMBO(comboDir)->entry), findInDir);
 	// Make a little wider than would happen automatically to show realistic paths
+#if GTK_MAJOR_VERSION >= 2
 	gtk_entry_set_width_chars(GTK_ENTRY(GTK_COMBO(comboDir)->entry), 40);
+#endif
 	gtk_signal_connect(GTK_OBJECT(GTK_COMBO(comboDir)->entry),
 	                   "activate", GtkSignalFunc(FindInFilesSignal), this);
 	gtk_combo_disable_activate(GTK_COMBO(comboDir));
@@ -1622,7 +1624,9 @@
 	                 row, row + 1, optse, opts, 5, 5);
 	gtk_widget_show(comboFind);
 	gtk_entry_set_text(GTK_ENTRY(GTK_COMBO(comboFind)->entry), findWhat.c_str());
+#if GTK_MAJOR_VERSION >= 2
 	gtk_entry_set_width_chars(GTK_ENTRY(GTK_COMBO(comboFind)->entry), 40);
+#endif
 	gtk_entry_select_region(GTK_ENTRY(GTK_COMBO(comboFind)->entry), 0, findWhat.length());
 	gtk_signal_connect(GTK_OBJECT(GTK_COMBO(comboFind)->entry),
 	                   "activate", GtkSignalFunc(FRFindSignal), this);
