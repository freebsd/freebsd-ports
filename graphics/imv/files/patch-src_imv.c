--- src/imv.c.orig	2024-01-06 21:47:38 UTC
+++ src/imv.c
@@ -1425,8 +1425,7 @@ static char *get_config_path(void)
     "$HOME/.config/imv/config",
     "$HOME/.imv_config",
     "$HOME/.imv/config",
-    "/usr/local/etc/imv_config",
-    "/etc/imv_config",
+    "@PREFIX@/etc/imv_config",
   };
 
   for (size_t i = 0; i < sizeof(config_paths) / sizeof(char*); ++i) {
