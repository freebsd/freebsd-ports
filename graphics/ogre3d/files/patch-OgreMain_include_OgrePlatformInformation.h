--- OgreMain/include/OgrePlatformInformation.h.orig	2013-12-01 18:28:12.000000000 +0100
+++ OgreMain/include/OgrePlatformInformation.h	2014-06-15 21:59:18.000000000 +0200
@@ -94,6 +94,7 @@
     OGRE_PLATFORM != OGRE_PLATFORM_NACL
 #   define __OGRE_HAVE_SSE  1
 #elif OGRE_DOUBLE_PRECISION == 0 && OGRE_CPU == OGRE_CPU_X86 && (OGRE_COMPILER == OGRE_COMPILER_GNUC || OGRE_COMPILER == OGRE_COMPILER_CLANG) && \
+      defined(__SSE__) && \
       OGRE_PLATFORM != OGRE_PLATFORM_APPLE_IOS && OGRE_PLATFORM != OGRE_PLATFORM_NACL
 #   define __OGRE_HAVE_SSE  1
 #endif

