
$FreeBSD$

--- OSSSurround-0.1/configure.c.orig	Sun Jan  6 14:36:17 2002
+++ OSSSurround-0.1/configure.c	Thu Aug  1 19:10:21 2002
@@ -136,7 +136,7 @@
 				}
 				else
 					item = gtk_menu_item_new_with_label(buffer);
-				gtk_signal_connect(GTK_OBJECT(item), "activate", sigfunc, (gpointer) index++);
+				gtk_signal_connect(GTK_OBJECT(item), "activate", sigfunc, GINT_TO_POINTER(index++));
 				gtk_widget_show(item);
 				gtk_menu_append(GTK_MENU(menu), item);
 			}
