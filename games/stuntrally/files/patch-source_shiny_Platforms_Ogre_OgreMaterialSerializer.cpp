--- source/shiny/Platforms/Ogre/OgreMaterialSerializer.cpp.orig	2022-11-11 19:35:22 UTC
+++ source/shiny/Platforms/Ogre/OgreMaterialSerializer.cpp
@@ -7,7 +7,7 @@
 #include <OgreLogManager.h>
 
 //#if 0  // for Ogre 1.9 only
-#if OGRE_VERSION >= MYGUI_DEFINE_VERSION(1, 12, 0)
+#if 1
 namespace Ogre
 {
     template <typename T> class MapIterator;
