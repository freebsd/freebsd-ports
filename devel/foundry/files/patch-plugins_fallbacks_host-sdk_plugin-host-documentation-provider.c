--- plugins/fallbacks/host-sdk/plugin-host-documentation-provider.c.orig	2025-10-28 23:23:12 UTC
+++ plugins/fallbacks/host-sdk/plugin-host-documentation-provider.c
@@ -52,9 +52,9 @@ plugin_host_documentation_provider_load_fiber (gpointe
       g_autoptr(FoundryDocumentationRoot) root = NULL;
       g_autoptr(GListStore) directories = g_list_store_new (G_TYPE_FILE);
       g_autoptr(GIcon) icon = g_themed_icon_new (os_icon ? os_icon : "go-home-symbolic");
-      g_autofree char *doc = plugin_host_sdk_build_filename (PLUGIN_HOST_SDK (sdk), "usr", "share", "doc", NULL);
-      g_autofree char *gtk_doc = plugin_host_sdk_build_filename (PLUGIN_HOST_SDK (sdk), "usr", "share", "gtk-doc", "html", NULL);
-      g_autofree char *devhelp = plugin_host_sdk_build_filename (PLUGIN_HOST_SDK (sdk), "usr", "share", "devhelp", "books", NULL);
+      g_autofree char *doc = plugin_host_sdk_build_filename (PLUGIN_HOST_SDK (sdk), "%%LOCALBASE%%", "share", "doc", NULL);
+      g_autofree char *gtk_doc = plugin_host_sdk_build_filename (PLUGIN_HOST_SDK (sdk), "%%LOCALBASE%%", "share", "gtk-doc", "html", NULL);
+      g_autofree char *devhelp = plugin_host_sdk_build_filename (PLUGIN_HOST_SDK (sdk), "%%LOCALBASE%%", "share", "devhelp", "books", NULL);
       g_autofree char *user_doc = g_build_filename (g_get_user_data_dir (), "doc", NULL);
       g_autofree char *user_gtk_doc = g_build_filename (g_get_user_data_dir (), "gtk-doc", "html", NULL);
       g_autofree char *user_devhelp = g_build_filename (g_get_user_data_dir (), "devhelp", "books", NULL);
