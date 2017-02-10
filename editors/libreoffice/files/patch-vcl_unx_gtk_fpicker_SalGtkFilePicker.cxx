--- vcl/unx/gtk/fpicker/SalGtkFilePicker.cxx.orig	2017-01-12 00:54:33 UTC
+++ vcl/unx/gtk/fpicker/SalGtkFilePicker.cxx
@@ -436,10 +436,13 @@ dialog_remove_buttons( GtkDialog *pDialo
 {
     g_return_if_fail( GTK_IS_DIALOG( pDialog ) );
 
-#if GTK_CHECK_VERSION(3,0,0)
 #if GTK_CHECK_VERSION(3,12,0)
-    dialog_remove_buttons(gtk_dialog_get_header_bar(pDialog));
+    GtkWidget *pHeaderBar = gtk_dialog_get_header_bar( pDialog );
+    if( pHeaderBar != nullptr )
+        dialog_remove_buttons( pHeaderBar );
+    else
 #endif
+#if GTK_CHECK_VERSION(2,14,0)
     dialog_remove_buttons(gtk_dialog_get_action_area(pDialog));
 #else
     dialog_remove_buttons(pDialog->action_area);
