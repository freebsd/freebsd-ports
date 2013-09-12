--- src/display/surface_manager.cpp.orig	2006-04-25 08:08:56.000000000 +0400
+++ src/display/surface_manager.cpp	2013-09-12 04:51:36.056226058 +0400
@@ -13,9 +13,10 @@
 #include "texture.hpp"
 #include "surface.hpp"
 #include "texture_manager.hpp"
+
 #include "physfs/physfs_sdl.hpp"
 
-SurfaceManager::SurfaceManager* surface_manager = 0;
+SurfaceManager* surface_manager = 0;
 
 SurfaceManager::SurfaceManager()
 {
