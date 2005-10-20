--- plugins/actor/gdkpixbuf/actor_gdkpixbuf.c.orig	Thu Oct 20 11:07:30 2005
+++ plugins/actor/gdkpixbuf/actor_gdkpixbuf.c	Thu Oct 20 11:08:06 2005
@@ -98,7 +98,7 @@ const VisPluginInfo *get_plugin_info (in
 int act_gdkpixbuf_init (VisPluginData *plugin)
 {
 	PixbufPrivate *priv;
-	VisParamContainer *paramcontainer = visual_plugin_get_params (plugin);;
+	VisParamContainer *paramcontainer = visual_plugin_get_params (plugin);
 	
 	static const VisParamEntry params[] = {
 		VISUAL_PARAM_LIST_ENTRY_STRING	("filename",	""),
