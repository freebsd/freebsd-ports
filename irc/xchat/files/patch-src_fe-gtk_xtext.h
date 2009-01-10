--- src/fe-gtk/xtext.h.orig	2008-08-06 09:47:05.000000000 +0200
+++ src/fe-gtk/xtext.h	2008-08-06 09:51:01.000000000 +0200
@@ -270,6 +270,6 @@ void gtk_xtext_set_wordwrap (GtkXText *x
 xtext_buffer *gtk_xtext_buffer_new (GtkXText *xtext);
 void gtk_xtext_buffer_free (xtext_buffer *buf);
 void gtk_xtext_buffer_show (GtkXText *xtext, xtext_buffer *buf, int render);
-GtkType gtk_xtext_get_type (void);
+GType gtk_xtext_get_type (void);
 
 #endif
