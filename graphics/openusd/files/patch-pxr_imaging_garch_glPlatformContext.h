--- pxr/imaging/garch/glPlatformContext.h.orig	2025-10-24 16:21:56 UTC
+++ pxr/imaging/garch/glPlatformContext.h
@@ -15,7 +15,7 @@
 #include <cstddef>
 #include <functional>
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_FREEBSD)
 
 #include "pxr/imaging/garch/glPlatformContextGLX.h"
 
