--- filament/backend/src/PlatformFactory.cpp.orig	2025-03-31 22:23:27 UTC
+++ filament/backend/src/PlatformFactory.cpp
@@ -41,7 +41,7 @@
             #include <backend/platforms/PlatformCocoaGL.h>
         #endif
     #endif
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     #if defined(FILAMENT_SUPPORTS_X11)
         #if defined(FILAMENT_SUPPORTS_OPENGL) && !defined(FILAMENT_USE_EXTERNAL_GLES3)
             #include "backend/platforms/PlatformGLX.h"
@@ -151,7 +151,7 @@ Platform* PlatformFactory::create(Backend* backend) no
             #else
                 return new PlatformCocoaGL();
             #endif
-        #elif defined(__linux__)
+        #elif defined(__linux__) || defined(__FreeBSD__)
             #if defined(FILAMENT_SUPPORTS_X11)
                 return new PlatformGLX();
             #elif defined(FILAMENT_SUPPORTS_EGL_ON_LINUX)
