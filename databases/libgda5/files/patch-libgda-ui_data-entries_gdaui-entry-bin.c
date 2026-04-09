--- libgda-ui/data-entries/gdaui-entry-bin.c.orig	2020-11-08 20:23:19 UTC
+++ libgda-ui/data-entries/gdaui-entry-bin.c
@@ -239,11 +239,11 @@ create_entry (GdauiEntryWrapper *mgwrap)
 
 	label = gtk_label_new ("");
 	gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 0);
-	dbin->priv->button_label = g_object_ref (G_OBJECT (label));
+	dbin->priv->button_label = (GtkWidget *) g_object_ref (G_OBJECT (label));
 
 	img = gtk_image_new_from_pixbuf (attach_pixbuf);
 	gtk_box_pack_start (GTK_BOX (hbox), img, FALSE, FALSE, 0);
-	dbin->priv->button_image = g_object_ref (G_OBJECT (img));
+	dbin->priv->button_image = (GtkWidget *) g_object_ref (G_OBJECT (img));
 
         arrow = gtk_arrow_new (GTK_ARROW_DOWN, GTK_SHADOW_NONE);
 	gtk_misc_set_alignment (GTK_MISC (arrow), 1.0, -1);
