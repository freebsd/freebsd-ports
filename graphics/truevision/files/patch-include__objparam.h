--- include/objparam.h.orig
+++ include/objparam.h
@@ -465,7 +465,7 @@
 			TvWidget_entry( name, sname, tooltip, appref, val) {}
 		ObjParam_entry( ObjParam_entry & ref ) : ObjParam( ref ), TvWidget_entry( ref ) {}
 		void get_widget( GtkWidget *box, bool tt );
-		void get_widget( GtkWidget *row, bool tt, int row );
+		void get_widget( GtkWidget *tab, bool tt, int row );
 		void flush();
 		void swap_data( ObjParam *param );
 };
