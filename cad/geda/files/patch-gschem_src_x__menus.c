--- gschem/src/x_menus.c.orig	2013-09-25 20:59:27 UTC
+++ gschem/src/x_menus.c
@@ -58,6 +58,7 @@ static GtkItemFactoryEntry popup_items[] = {
   {N_("/Up"),             NULL, i_callback_hierarchy_up,             0, NULL},
 };  
 
+GtkRecentManager *recent_manager;
 int npopup_items = sizeof(popup_items) / sizeof(popup_items[0]);
 
 /*! \todo Finish function documentation!!!
