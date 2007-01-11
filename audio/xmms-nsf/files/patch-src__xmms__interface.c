--- ./src/xmms/interface.c.orig	Sun Jul 23 11:41:14 2000
+++ ./src/xmms/interface.c	Wed Jan 10 20:10:34 2007
@@ -106,7 +106,7 @@
   gtk_label_set_justify (GTK_LABEL (label2), GTK_JUSTIFY_LEFT);
   gtk_misc_set_alignment (GTK_MISC (label2), 0, 0.5);
 
-  label3 = gtk_label_new ("Fadeout Time:");
+  label3 = gtk_label_new ("Silence Until Next Song:");
   gtk_widget_ref (label3);
   gtk_object_set_data_full (GTK_OBJECT (configure), "label3", label3,
                             (GtkDestroyNotify) gtk_widget_unref);
