--- src/marlin-window-menu.c.orig	Thu Aug  5 12:47:19 2004
+++ src/marlin-window-menu.c	Wed Aug 11 22:06:41 2004
@@ -634,8 +634,8 @@
 	GtkWidget *editor, *dialog;
 	EphyToolbarsModel *model;
 	Toolbar *toolbar;
-	GtkUIManager *ui_manager = marlin_window_get_menu_merge (MARLIN_WINDOW (data));;
 	char *xml;
+	GtkUIManager *ui_manager = marlin_window_get_menu_merge (MARLIN_WINDOW (data));;
 
 	toolbar = marlin_window_get_toolbar (MARLIN_WINDOW (data));
 	model = marlin_get_toolbars_model ();
