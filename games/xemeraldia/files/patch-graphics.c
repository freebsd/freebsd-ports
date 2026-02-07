--- ./graphics.c.orig	2009-02-10 01:55:24.000000000 +0100
+++ ./graphics.c	2014-03-31 00:27:54.287686028 +0200
@@ -7,6 +7,7 @@
 #endif
 
 #include "games.h"
+#include "gtk-2.0/gtk/gtkprivate.h"
 
 static gboolean animateTmpScore (void *);
 
@@ -32,7 +33,7 @@
 
 static void invalidate_area(GtkWidget *widget, gint x, gint y, gint w, gint h)
 {
-	while(GTK_WIDGET_FLAGS(widget) & GTK_NO_WINDOW)
+	while(GTK_PRIVATE_FLAGS(widget) & GTK_NO_WINDOW)
 	{
 		x += widget->allocation.x;
 		y += widget->allocation.y;
