--- src/plugin-templates.c.orig	Mon Oct 27 23:37:32 2003
+++ src/plugin-templates.c	Thu Oct 30 18:50:50 2003
@@ -169,12 +169,12 @@
 {
 	int i;
 	GSList* template_paths;
+	CongTemplate* template;
 
 	g_return_val_if_fail(plugin, FALSE);
 
 	template_paths = get_template_paths(plugin);
 
-	CongTemplate* template;
 	template = g_new0(CongTemplate, sizeof(template));
 	template->plugin = plugin;
 
