
$FreeBSD$

--- glade/gnome-db/gnomedberrordlg.c	2001/08/13 09:48:33	1.1
+++ glade/gnome-db/gnomedberrordlg.c	2001/08/13 09:52:31
@@ -60,7 +60,7 @@
   GtkWidget *widget;
   GList *elem;
 
-  widget = gnome_db_errordlg_new (NULL, _("Error"));
+  widget = gnome_db_error_dialog_new (_("Error"));
 
   /* Stop the normal dismiss operation since it can cause a crash. */
   elem = g_list_nth (GNOME_DIALOG (widget)->buttons, 2);
@@ -155,7 +155,7 @@
       gchar *title;
 
       title = GTK_WINDOW (widget)->title;
-      source_add (data, "  %s = gnome_db_errordlg_new (NULL, %s);\n",
+      source_add (data, "  %s = gnome_db_error_dialog_new (%s);\n",
 		  data->wname,
 		  title ? source_make_string (title, data->use_gettext)
 		        : "NULL");
@@ -182,7 +182,7 @@
 gb_gnome_db_errordlg_init ()
 {
   /* Initialise the GTK type */
-  gnome_db_errordlg_get_type();
+  gnome_db_error_dialog_get_type();
 
   /* Initialize the GbWidget structure */
   gb_widget_init_struct(&gbwidget);
