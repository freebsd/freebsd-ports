--- src/mlview-app-context.c.orig	Tue Jan 11 09:37:44 2005
+++ src/mlview-app-context.c	Tue Jan 11 09:38:02 2005
@@ -1348,13 +1348,14 @@
 mlview_app_context_get_file_chooser (MlViewAppContext *a_this,
                                      const gchar *a_title, MlViewFileChooserMode a_mode)
 {
+	GtkWidget * parent_window = NULL ;
+
         g_return_val_if_fail (a_this 
                               && MLVIEW_IS_APP_CONTEXT (a_this)
                               && PRIVATE (a_this),
                               NULL) ;
 
         /*if (!PRIVATE (a_this)->file_chooser) {*/
-	GtkWidget * parent_window = NULL ;
 
 	parent_window = mlview_app_context_get_element (a_this,
 							"MlViewMainWindow") ;
