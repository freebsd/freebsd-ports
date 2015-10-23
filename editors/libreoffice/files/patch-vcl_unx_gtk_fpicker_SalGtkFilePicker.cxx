--- vcl/unx/gtk/fpicker/SalGtkFilePicker.cxx.orig	2015-09-17 13:33:12 UTC
+++ vcl/unx/gtk/fpicker/SalGtkFilePicker.cxx
@@ -421,13 +421,18 @@ shrinkFilterName( const OUString &rFilte
 static void
 dialog_remove_buttons(GtkWidget *pActionArea)
 {
-    GList *pChildren =
-        gtk_container_get_children( GTK_CONTAINER( pActionArea ) );
+    GtkContainer * container = GTK_CONTAINER( pActionArea );
 
-    for( GList *p = pChildren; p; p = p->next )
-        gtk_widget_destroy( GTK_WIDGET( p->data ) );
+    if( container )
+    {
+        GList *pChildren =
+            gtk_container_get_children( container );
 
-    g_list_free( pChildren );
+        for( GList *p = pChildren; p; p = p->next )
+            gtk_widget_destroy( GTK_WIDGET( p->data ) );
+
+        g_list_free( pChildren );
+    }
 }
 
 static void
