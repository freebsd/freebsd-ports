
$FreeBSD$

--- glade/gnome-db/gnomedblogin.c	2002/01/28 13:18:44	1.1
+++ glade/gnome-db/gnomedblogin.c	2002/01/28 13:19:07
@@ -117,7 +117,7 @@
 {
   if (data->create_widget)
     {
-      source_add (data, "  %s = gnome_db_login_new (NULL, NULL, NULL);\n",
+      source_add (data, "  %s = gnome_db_login_new (NULL);\n",
 		  data->wname);
     }
   gb_widget_write_standard_source (widget, data);
