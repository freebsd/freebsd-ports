--- src/display/texture_manager.cpp.orig	2006-03-11 16:50:05.000000000 +0300
+++ src/display/texture_manager.cpp	2013-09-12 04:43:09.595227271 +0400
@@ -13,7 +13,7 @@
 #include "texture.hpp"
 #include "physfs/physfs_sdl.hpp"
 
-TextureManager::TextureManager* texture_manager = 0;
+TextureManager* texture_manager = 0;
 
 TextureManager::TextureManager()
 {
