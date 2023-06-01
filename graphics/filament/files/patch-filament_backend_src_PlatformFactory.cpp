--- filament/backend/src/PlatformFactory.cpp.orig	2023-05-30 23:22:31 UTC
+++ filament/backend/src/PlatformFactory.cpp
@@ -32,7 +32,7 @@
     #if defined(FILAMENT_SUPPORTS_OPENGL) && !defined(FILAMENT_USE_EXTERNAL_GLES3) && !defined(FILAMENT_USE_SWIFTSHADER)
         #include <backend/platforms/PlatformCocoaGL.h>
     #endif
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     #if defined(FILAMENT_SUPPORTS_X11)
         #if defined(FILAMENT_SUPPORTS_OPENGL) && !defined(FILAMENT_USE_EXTERNAL_GLES3) && !defined(FILAMENT_USE_SWIFTSHADER)
             #include "backend/platforms/PlatformGLX.h"
@@ -120,7 +120,7 @@ Platform* PlatformFactory::create(Backend* backend) no
             return new PlatformCocoaTouchGL();
         #elif defined(__APPLE__)
             return new PlatformCocoaGL();
-        #elif defined(__linux__)
+        #elif defined(__linux__) || defined(__FreeBSD__)
             #if defined(FILAMENT_SUPPORTS_X11)
                 return new PlatformGLX();
             #elif defined(FILAMENT_SUPPORTS_EGL_ON_LINUX)
