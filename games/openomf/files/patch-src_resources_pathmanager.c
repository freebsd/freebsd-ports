--- src/resources/pathmanager.c.orig	2016-01-10 17:37:25 UTC
+++ src/resources/pathmanager.c
@@ -85,11 +85,11 @@ int pm_init() {
                 local_path_build(RESOURCE_PATH, bin_base_dir, "resources\\");
                 local_path_build(PLUGIN_PATH, bin_base_dir, "plugins\\");
                 m_ok = 1;
-            } else if(!strcasecmp(SDL_GetPlatform(), "Linux")) {
+            } else if(!strcasecmp(SDL_GetPlatform(), "FreeBSD")) {
                 // on linux, the resources will be in ../share/games/openomf, relative to the binary
                 // so if openomf is installed to /usr/local/bin,
                 // the resources will be in /usr/local/share/games/openomf
-                local_path_build(RESOURCE_PATH, bin_base_dir, "../share/games/openomf/");
+                local_path_build(RESOURCE_PATH, %%PREFIX%%, "/share/openomf/");
                 local_path_build(PLUGIN_PATH, bin_base_dir, "../lib/openomf/");
                 m_ok = 1;
             } else if(!strcasecmp(SDL_GetPlatform(), "Mac OS X")) {
