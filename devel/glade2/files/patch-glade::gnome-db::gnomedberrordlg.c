
$FreeBSD$

--- glade/gnome-db/gnomedberrordlg.c	2002/01/28 13:15:07	1.1
+++ glade/gnome-db/gnomedberrordlg.c	2002/01/28 13:14:41
@@ -155,7 +155,7 @@
       gchar *title;
 
       title = GTK_WINDOW (widget)->title;
-      source_add (data, "  %s = gnome_db_error_dialog_new (NULL, %s);\n",
+      source_add (data, "  %s = gnome_db_error_dialog_new (%s);\n",
 		  data->wname,
 		  title ? source_make_string (title, data->use_gettext)
 		        : "NULL");
