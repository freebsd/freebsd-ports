--- client/human/chmain.cpp.orig	2010-01-10 17:21:20.000000000 +0100
+++ client/human/chmain.cpp	2010-01-10 17:18:12.000000000 +0100
@@ -22,6 +22,7 @@
 #include <OgreRoot.h>
 #include <OgreSceneManager.h>
 #include <OgreViewport.h>
+#include <OgreConfigFile.h>
 
 #include <boost/lexical_cast.hpp>
 #include <boost/format.hpp>
@@ -172,6 +173,24 @@
 
         root = new Root((GetRootDataDir() / "ogre_plugins.cfg").string());
 
+        Ogre::ConfigFile cf;
+        cf.load((GetRootDataDir() / "resources.cfg").file_string());
+
+        // Go through all sections & settings in the file
+        Ogre::ConfigFile::SectionIterator section_it = cf.getSectionIterator();
+        while (section_it.hasMoreElements()) {
+            Ogre::String section_name = section_it.peekNextKey();
+            Ogre::ConfigFile::SettingsMultiMap *settings = section_it.getNext();
+            for (Ogre::ConfigFile::SettingsMultiMap::iterator it = settings->begin();
+                 it != settings->end();
+                 ++it) {
+                Ogre::String type_name = it->first, path_name = it->second;
+                Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
+                    (ClientUI::ArtDir() / path_name).file_string(),
+                    type_name, section_name);
+            }
+        }
+
 #if defined(OGRE_STATIC_LIB)
         cg_plugin = new Ogre::CgPlugin;
         octree_plugin = new Ogre::OctreePlugin;
