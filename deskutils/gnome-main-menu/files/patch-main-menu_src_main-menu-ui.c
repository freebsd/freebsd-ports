--- main-menu/src/main-menu-ui.c.orig	2008-07-06 22:31:43.000000000 -0400
+++ main-menu/src/main-menu-ui.c	2008-07-06 22:33:32.000000000 -0400
@@ -47,7 +47,6 @@
 #include "directory-tile.h"
 #include "system-tile.h"
 #include "hard-drive-status-tile.h"
-#include "network-status-tile.h"
 
 #include "tile-table.h"
 
@@ -100,7 +99,6 @@ typedef struct {
 
 	GtkWidget *search_section;
 	GtkWidget *search_entry;
-	GtkWidget *network_status;
 
 	GtkNotebook *file_section;
 	GtkWidget   *page_selectors    [3];
@@ -405,7 +403,6 @@ main_menu_ui_init (MainMenuUI *this)
 
 	priv->status_section                             = NULL;
 	priv->system_section                             = NULL;
-	priv->network_status                             = NULL;
 
 	priv->volume_mon                                 = NULL;
 
@@ -730,19 +727,6 @@ create_status_section (MainMenuUI *this)
 	gtk_container_add   (ctnr, tile);
 	gtk_widget_show_all (GTK_WIDGET (ctnr));
 
-	ctnr = GTK_CONTAINER (glade_xml_get_widget (
-		priv->main_menu_xml, "network-status-container"));
-	priv->network_status = network_status_tile_new ();
-
-	gtk_widget_set_size_request (priv->network_status, 6 * icon_width, -1);
-
-	g_signal_connect (
-		G_OBJECT (priv->network_status), "tile-action-triggered",
-		G_CALLBACK (tile_action_triggered_cb), this);
-
-	gtk_container_add   (ctnr, priv->network_status);
-	gtk_widget_show_all (GTK_WIDGET (ctnr));
-
 	priv->status_section = glade_xml_get_widget (
 		priv->main_menu_xml, "slab-status-section");
 }
@@ -1853,8 +1837,6 @@ present_slab_window (MainMenuUI *this)
 {
 	MainMenuUIPrivate *priv = PRIVATE (this);
 
-	network_tile_update_status (priv->network_status);
-
 	update_recently_used_sections (this);
 
 	gtk_window_present_with_time (GTK_WINDOW (priv->slab_window), gtk_get_current_event_time ());
