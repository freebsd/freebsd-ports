--- frend.cc.orig	2009-12-21 22:38:54 UTC
+++ frend.cc
@@ -2527,7 +2527,7 @@ void Window::addMenu(const char*label, M
 	{
 		if(strcmp(items[i].label, "-"))
 		{
-			if(items[i].icon > 0)
+			if(items[i].icon)
 			{
 				menu_item = gtk_menu_item_new();
 				GtkWidget *hbox = gtk_hbox_new(false, false);
