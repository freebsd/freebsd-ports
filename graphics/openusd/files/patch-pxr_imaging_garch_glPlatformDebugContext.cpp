--- pxr/imaging/garch/glPlatformDebugContext.cpp.orig	2025-10-24 16:21:56 UTC
+++ pxr/imaging/garch/glPlatformDebugContext.cpp
@@ -34,7 +34,7 @@ PXR_NAMESPACE_CLOSE_SCOPE
 PXR_NAMESPACE_CLOSE_SCOPE
 
 ////////////////////////////////////////////////////////////
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_FREEBSD)
 
 #include <GL/glx.h>
 #include <GL/glxtokens.h>
