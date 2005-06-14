--- src/gui-netlist-window.c.orig	Tue Mar  1 14:33:01 2005
+++ src/gui-netlist-window.c	Mon Jun 13 09:04:32 2005
@@ -692,7 +692,7 @@
 	{
 	GtkTreePath			*path;
 	GtkTreeIter			iter;
-	LibraryMenuType		*net;;
+	LibraryMenuType		*net;
 	gchar				*name;
 
 	if (!node_name)
