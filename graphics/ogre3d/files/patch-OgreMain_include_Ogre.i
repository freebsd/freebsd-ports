--- OgreMain/include/Ogre.i.orig	2023-07-07 21:29:06 UTC
+++ OgreMain/include/Ogre.i
@@ -611,7 +611,7 @@ SHARED_PTR(HardwarePixelBuffer);
 %ignore Ogre::ResourceGroupManager::openResource(const String&, const String&, bool) const;
 %ignore Ogre::ResourceGroupManager::getResourceManagerIterator;
 %include "OgreResourceGroupManager.h"
-#if SWIG_VERSION < 0x030012 || defined(SWIGJAVA)
+#if SWIG_VERSION <= 0x030012 || defined(SWIGJAVA)
 // conflicts with overloaded versions (GpuProgram, Texture)
 %ignore Ogre::ResourceManager::getResourceByName;
 %ignore Ogre::ResourceManager::createOrRetrieve;
