
$FreeBSD$

--- glade/gnome-db/gnomedberror.c	2001/08/13 09:43:59	1.1
+++ glade/gnome-db/gnomedberror.c	2001/08/13 09:44:25
@@ -46,7 +46,7 @@
 static GtkWidget*
 gb_gnome_db_error_new (GbWidgetNewData *data)
 {
-  return gnome_db_error_new (NULL);
+  return gnome_db_error_new ();
 }
 
 
