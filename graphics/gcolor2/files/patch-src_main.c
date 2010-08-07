--- src/main.c.orig	2010-06-21 22:38:34.000000000 +0200
+++ src/main.c	2010-06-21 22:36:23.000000000 +0200
@@ -9,6 +9,11 @@
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
@@ -48,8 +53,6 @@
 
 void add_list_color (gchar *spec, gchar *name, gchar *type, gboolean is_new_color)
 {
-	GdkPixmap   *pixmap;
-	GdkBitmap   *mask;
 	GdkPixbuf   *buf;
 	GtkTreeIter  iter;
 	
@@ -103,7 +106,7 @@
 	gchar *name;
 	gchar  buffer[512];
 	gchar  spec[8];
-	gint   r, g, b, lr, lg, lb;
+	gint   r, g, b, lr=0, lg=0, lb=0;
 	
 	fp = fopen (filename, "r");
 	if (!fp)
@@ -140,7 +143,6 @@
 	GtkTreeViewColumn *column;
 	GtkWidget         *treeview;
 	GtkTreeSelection  *select;
-	gchar             *buf;
 	
 #ifdef ENABLE_NLS
 	bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
