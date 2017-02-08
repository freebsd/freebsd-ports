--- vcl/unx/gtk/fpicker/SalGtkFilePicker.cxx.orig	2017-01-12 00:54:33 UTC
+++ vcl/unx/gtk/fpicker/SalGtkFilePicker.cxx
@@ -418,8 +418,11 @@ shrinkFilterName( const OUString &rFilte
 static void
 dialog_remove_buttons(GtkWidget *pActionArea)
 {
-    GList *pChildren =
-        gtk_container_get_children( GTK_CONTAINER( pActionArea ) );
+    GtkContainer *pContainer = GTK_CONTAINER( pActionArea );
+
+    g_return_if_fail( pContainer != nullptr );
+
+    GList *pChildren = gtk_container_get_children( pContainer );
 
     for( GList *p = pChildren; p; p = p->next )
     {
@@ -436,10 +439,10 @@ dialog_remove_buttons( GtkDialog *pDialo
 {
     g_return_if_fail( GTK_IS_DIALOG( pDialog ) );
 
-#if GTK_CHECK_VERSION(3,0,0)
 #if GTK_CHECK_VERSION(3,12,0)
     dialog_remove_buttons(gtk_dialog_get_header_bar(pDialog));
 #endif
+#if GTK_CHECK_VERSION(2,14,0)
     dialog_remove_buttons(gtk_dialog_get_action_area(pDialog));
 #else
     dialog_remove_buttons(pDialog->action_area);
