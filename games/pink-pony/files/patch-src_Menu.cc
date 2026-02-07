--- src/Menu.cc.orig	2025-05-13 14:45:49 UTC
+++ src/Menu.cc
@@ -88,7 +88,7 @@ Menu::Menu (Config* config, 
     : active_screen(MAIN_SCREEN),
       config(config),
       skydome(skydome),
-      heightmap(NULL),
+      heightmap(nullptr),
       logo_button(config->resource_dir + "textures/logo.png"),
       start_button("Start", config),
       quit_button(config->resource_dir + "textures/quit.png"),
