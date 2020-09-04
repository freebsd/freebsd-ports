--- src/main.c.orig	2005-07-11 14:55:49 UTC
+++ src/main.c
@@ -9,11 +9,19 @@
 #include "support.h"
 #include "callbacks.h"
 
+/* missing headers on original file */
+#include <stdlib.h>
+#include <string.h>
+#include <glib/gprintf.h>
+
 GtkListStore *liststore;
 GdkWindow    *gdkwin;
 gchar        *user_filename;
 gchar        *sys_filename;
 
+GtkWidget *gcolor2;
+GtkWidget *menu;
+GdkColor   colorvalue;
 
 void set_user_file ()
 {
@@ -48,8 +56,6 @@
 
 void add_list_color (gchar *spec, gchar *name, gchar *type, gboolean is_new_color)
 {
-	GdkPixmap   *pixmap;
-	GdkBitmap   *mask;
 	GdkPixbuf   *buf;
 	GtkTreeIter  iter;
 	
@@ -103,7 +109,7 @@
 	gchar *name;
 	gchar  buffer[512];
 	gchar  spec[8];
-	gint   r, g, b, lr, lg, lb;
+	gint   r, g, b, lr=0, lg=0, lb=0;
 	
 	fp = fopen (filename, "r");
 	if (!fp)
@@ -140,7 +146,6 @@
 	GtkTreeViewColumn *column;
 	GtkWidget         *treeview;
 	GtkTreeSelection  *select;
-	gchar             *buf;
 	
 #ifdef ENABLE_NLS
 	bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
