--- OgreMain/include/Ogre.i.orig	2019-03-30 12:47:36 UTC
+++ OgreMain/include/Ogre.i
@@ -386,7 +386,7 @@ SHARED_PTR(HardwareUniformBuffer);
 %ignore Ogre::ResourceGroupManager::openResource(const String&, const String&, bool, Resource*) const;
 %ignore Ogre::ResourceGroupManager::openResource(const String&, const String&, bool) const;
 %include "OgreResourceGroupManager.h"
-#if SWIG_VERSION < 0x030012 || defined(SWIGJAVA)
+#if SWIG_VERSION <= 0x030012 || defined(SWIGJAVA)
 // conflicts with overloaded versions (GpuProgram, Texture)
 %ignore Ogre::ResourceManager::getResourceByName;
 %ignore Ogre::ResourceManager::createOrRetrieve;
