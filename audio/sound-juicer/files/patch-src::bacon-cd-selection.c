--- src/bacon-cd-selection.c.orig	Sun Dec 12 10:27:00 2004
+++ src/bacon-cd-selection.c	Sun Dec 12 10:27:57 2004
@@ -179,10 +179,10 @@
 static void
 bacon_cd_selection_init (BaconCdSelection *bcs)
 {
-	bcs->priv = g_new0 (BaconCdSelectionPrivate, 1);
-  
 	GtkCellRenderer *cell;
 	GtkListStore *store;
+
+	bcs->priv = g_new0 (BaconCdSelectionPrivate, 1);
 
   store = gtk_list_store_new (1, G_TYPE_STRING);
 	gtk_combo_box_set_model (GTK_COMBO_BOX (bcs),
