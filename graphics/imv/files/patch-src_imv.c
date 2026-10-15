--- src/imv.c.orig	2025-11-27 20:03:44 UTC
+++ src/imv.c
@@ -1476,8 +1476,7 @@ static char *get_config_path(void)
     "$HOME/.config/imv/config",
     "$HOME/.imv_config",
     "$HOME/.imv/config",
-    "/usr/local/etc/imv_config",
-    "/etc/imv_config",
+    "@PREFIX@/etc/imv_config",
   };
 
   for (size_t i = 0; i < sizeof(config_paths) / sizeof(char*); ++i) {
