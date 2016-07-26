--- src/xmms/interface.c.orig	2000-07-23 09:41:14 UTC
+++ src/xmms/interface.c
@@ -106,7 +106,7 @@ create_configure (void)
   gtk_label_set_justify (GTK_LABEL (label2), GTK_JUSTIFY_LEFT);
   gtk_misc_set_alignment (GTK_MISC (label2), 0, 0.5);
 
-  label3 = gtk_label_new ("Fadeout Time:");
+  label3 = gtk_label_new ("Silence Until Next Song:");
   gtk_widget_ref (label3);
   gtk_object_set_data_full (GTK_OBJECT (configure), "label3", label3,
                             (GtkDestroyNotify) gtk_widget_unref);
