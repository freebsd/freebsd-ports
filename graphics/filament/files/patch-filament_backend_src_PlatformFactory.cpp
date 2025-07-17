--- filament/backend/src/PlatformFactory.cpp.orig	2025-07-14 23:11:31 UTC
+++ filament/backend/src/PlatformFactory.cpp
@@ -42,7 +42,7 @@
             #include <backend/platforms/PlatformCocoaGL.h>
         #endif
     #endif
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     #if defined(FILAMENT_SUPPORTS_X11)
         #if defined(FILAMENT_SUPPORTS_OPENGL) && !defined(FILAMENT_USE_EXTERNAL_GLES3)
             #include "backend/platforms/PlatformGLX.h"
@@ -152,7 +152,7 @@ Platform* PlatformFactory::create(Backend* backend) no
             #else
                 return new PlatformCocoaGL();
             #endif
-        #elif defined(__linux__)
+        #elif defined(__linux__) || defined(__FreeBSD__)
             #if defined(FILAMENT_SUPPORTS_X11)
                 return new PlatformGLX();
             #elif defined(FILAMENT_SUPPORTS_EGL_ON_LINUX)
