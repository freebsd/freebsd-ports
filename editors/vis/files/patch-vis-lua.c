--- vis-lua.c.orig	2024-05-01 19:49:18 UTC
+++ vis-lua.c
@@ -27,7 +27,7 @@
 #include "util.h"
 
 #ifndef VIS_PATH
-#define VIS_PATH "/usr/local/share/vis"
+#define VIS_PATH "%%PREFIX%%/share/vis"
 #endif
 
 #define VIS_LUA_TYPE_VIS "vis"
@@ -3248,7 +3248,7 @@ void vis_lua_init(Vis *vis) {
 			home = pw->pw_dir;
 	}
 
-	vis_lua_path_add(vis, "/etc/vis");
+	vis_lua_path_add(vis, "%%ETCDIR%%");
 
 	const char *xdg_config = getenv("XDG_CONFIG_HOME");
 	if (xdg_config) {
