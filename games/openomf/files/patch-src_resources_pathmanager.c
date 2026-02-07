--- src/resources/pathmanager.c.orig	2016-01-10 17:37:25 UTC
+++ src/resources/pathmanager.c
@@ -133,6 +133,13 @@ int pm_init() {
                 local_path_build(RESOURCE_PATH, bin_base_dir, "../share/games/openomf/");
                 local_path_build(SHADER_PATH, bin_base_dir, "../share/games/openomf/shaders/");
                 m_ok = 1;
+            } else if(strcmp(SDL_GetPlatform(), "FreeBSD") == 0) {
+                // on FreeBSD, the resources will be in ../share/openomf, relative to the binary
+                // so if openomf is installed to %%PREFIX%%/bin,
+                // the resources will be in %%PREFIX%%/share/openomf
+                local_path_build(RESOURCE_PATH, bin_base_dir, "../share/openomf/");
+                local_path_build(SHADER_PATH, bin_base_dir, "../share/openomf/shaders/");
+                m_ok = 1;
             } else if(strcmp(SDL_GetPlatform(), "Mac OS X") == 0) {
                 // on OSX, GetBasePath returns the 'Resources' directory
                 // if run from an app bundle, so we can use this as-is
