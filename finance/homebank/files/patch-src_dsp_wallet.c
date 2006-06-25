--- src/dsp_wallet.c.orig	Sat Jun 24 20:41:27 2006
+++ src/dsp_wallet.c	Sat Jun 24 20:41:55 2006
@@ -82,8 +82,8 @@
 void wallet_update(GtkWidget *widget, gpointer user_data);
 void wallet_check_automated(GtkWidget *widget, gpointer user_data);
 void wallet_addoperations(GtkWidget *widget, gpointer user_data);
-void wallet_importamiga(GtkWidget *widget, gpointer user_data);
-void wallet_importgrisbi(GtkWidget *widget, gpointer user_data);
+void wallet_import_amiga(GtkWidget *widget, gpointer user_data);
+void wallet_import_grisbi(GtkWidget *widget, gpointer user_data);
 
 
 enum
