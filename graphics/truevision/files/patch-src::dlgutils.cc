--- src/dlgutils.cc.orig	Tue Jan  1 20:43:01 2002
+++ src/dlgutils.cc	Thu Jun 26 02:27:31 2003
@@ -41,7 +41,7 @@
 }
 
 // Double box
-GtkWidget *dlg_double_box( GtkWidget *parent, GtkWidget* &vbox1, GtkWidget* &vbox2, bool packed = false )
+GtkWidget *dlg_double_box( GtkWidget *parent, GtkWidget* &vbox1, GtkWidget* &vbox2, bool packed )
 {
 GtkWidget *hbox = gtk_hbox_new( TRUE, 5 );
 if ( packed ) gtk_box_pack_start( GTK_BOX(parent), hbox, TRUE, TRUE, 1 );
