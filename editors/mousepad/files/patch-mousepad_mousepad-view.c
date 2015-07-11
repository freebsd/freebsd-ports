--- mousepad/mousepad-view.c.orig	2014-09-01 20:50:07 UTC
+++ mousepad/mousepad-view.c
@@ -257,7 +257,8 @@ mousepad_view_buffer_changed (MousepadVi
       GtkSourceStyleScheme        *scheme;
 
       manager = gtk_source_style_scheme_manager_get_default ();
-      scheme = gtk_source_style_scheme_manager_get_scheme (manager, view->color_scheme);
+      scheme = gtk_source_style_scheme_manager_get_scheme (manager,
+        view->color_scheme ? view->color_scheme : "");
       gtk_source_buffer_set_style_scheme (buffer, scheme);
 
       gtk_source_buffer_set_highlight_matching_brackets (buffer, view->match_braces);
