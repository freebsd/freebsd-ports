--- glade/gnome-db/gnomedbsqleditor.c.orig	Sun Feb  9 15:13:09 2003
+++ glade/gnome-db/gnomedbsqleditor.c	Sun Feb  9 15:17:23 2003
@@ -19,7 +19,8 @@
 #include <config.h>
 
 #include <gtk/gtk.h>
-#include <libgnomedb/gnome-db-sql-editor.h>
+#include <libgnomedb/gnome-db-editor.h>
+
 #include "../gb.h"
 
 /* Include the 21x21 icon pixmap for this widget, to be used in the palette */
@@ -137,7 +138,7 @@
 {
   /* Initialise the GTK type */
   volatile GtkType type;
-  type = gnome_db_sql_editor_get_type();
+  type = gnome_db_editor_get_type();
 
   /* Initialize the GbWidget structure */
   gb_widget_init_struct(&gbwidget);
