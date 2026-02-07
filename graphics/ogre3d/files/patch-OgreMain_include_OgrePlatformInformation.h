--- OgreMain/include/OgrePlatformInformation.h.orig	2025-07-24 17:32:02 UTC
+++ OgreMain/include/OgrePlatformInformation.h
@@ -36,7 +36,7 @@ namespace Ogre {
 #if   OGRE_DOUBLE_PRECISION == 0 && OGRE_CPU == OGRE_CPU_X86 && OGRE_COMPILER == OGRE_COMPILER_MSVC
 #   define __OGRE_HAVE_SSE  1
 #elif OGRE_DOUBLE_PRECISION == 0 && OGRE_CPU == OGRE_CPU_X86 && (OGRE_COMPILER == OGRE_COMPILER_GNUC || OGRE_COMPILER == OGRE_COMPILER_CLANG) && \
-      OGRE_PLATFORM != OGRE_PLATFORM_APPLE_IOS
+      OGRE_PLATFORM != OGRE_PLATFORM_APPLE_IOS && defined(__amd64__)
 #   define __OGRE_HAVE_SSE  1
 #endif
