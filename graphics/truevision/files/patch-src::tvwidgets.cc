--- src/tvwidgets.cc.orig	Tue Jan  1 20:43:01 2002
+++ src/tvwidgets.cc	Thu Jun 26 02:23:39 2003
@@ -56,7 +56,7 @@
 in_update = false;
 }
 
-void TvWidget::pack_widget( GtkWidget *box, bool tt, GtkWidget *target=NULL )
+void TvWidget::pack_widget( GtkWidget *box, bool tt, GtkWidget *target )
 {
 if ( tt && tooltip != NULL ) 
 	{
