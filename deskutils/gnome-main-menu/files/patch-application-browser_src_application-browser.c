--- application-browser/src/application-browser.c.orig	2008-07-06 23:02:33.000000000 -0400
+++ application-browser/src/application-browser.c	2008-07-06 23:02:50.000000000 -0400
@@ -83,7 +83,7 @@ main (int argc, char *argv[])
 	NewAppConfig *config = g_new0 (NewAppConfig, 1);
 	config->max_items = get_slab_gconf_int (NEW_APPS_MAX_ITEMS);
 	config->name = _("New Applications");
-	AppShellData *app_data = appshelldata_new ("applications.menu", config,
+	AppShellData *app_data = appshelldata_new ("gnome-applications.menu", config,
 		APPLICATION_BROWSER_PREFIX, GTK_ICON_SIZE_DND, TRUE, FALSE);
 	generate_categories (app_data);
 
