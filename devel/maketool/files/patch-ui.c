$FreeBSD$

Author: Greg Banks

--- ui.c	8 Oct 2003 13:27:31 -0000	1.40
+++ ui.c	22 Oct 2003 12:13:21 -0000	1.41
@@ -347,8 +347,9 @@
 	gtk_menu_append(GTK_MENU(menu), item);
     else
 	gtk_menu_insert(GTK_MENU(menu), item, position);
-    gtk_signal_connect(GTK_OBJECT(item), "activate", 
-    	GTK_SIGNAL_FUNC(callback), calldata);
+    if (callback != 0)
+	gtk_signal_connect(GTK_OBJECT(item), "activate", 
+    	    GTK_SIGNAL_FUNC(callback), calldata);
     if (group >= 0)
     	ui_group_add(group, item);

