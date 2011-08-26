--- gtkpool/options.cpp.orig	2002-07-29 14:16:51.000000000 +0900
+++ gtkpool/options.cpp	2011-08-19 04:36:56.000000000 +0900
@@ -68,7 +68,7 @@
 	opt_dlg = gtk_dialog_new ();
 	gtk_object_set_data (GTK_OBJECT (opt_dlg), "opt_dlg", opt_dlg);
 	gtk_window_set_title (GTK_WINDOW (opt_dlg), _("GTKPool Options"));
-	GTK_WINDOW (opt_dlg)->type = GTK_WINDOW_DIALOG;
+	GTK_WINDOW (opt_dlg)->type = GTK_WINDOW_TOPLEVEL;
 	gtk_window_set_position (GTK_WINDOW (opt_dlg), GTK_WIN_POS_CENTER);
 	gtk_window_set_policy (GTK_WINDOW (opt_dlg), FALSE, TRUE, FALSE);
 	gtk_widget_ref (opt_dlg);
