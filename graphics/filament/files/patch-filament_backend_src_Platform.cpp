--- filament/backend/src/Platform.cpp.orig	2022-08-16 18:01:04 UTC
+++ filament/backend/src/Platform.cpp
@@ -41,7 +41,7 @@
     #if defined(FILAMENT_DRIVER_SUPPORTS_VULKAN)
         #include "vulkan/PlatformVkCocoa.h"
     #endif
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     #if defined(FILAMENT_SUPPORTS_WAYLAND)
         #if defined (FILAMENT_DRIVER_SUPPORTS_VULKAN)
             #include "vulkan/PlatformVkLinuxWayland.h"
@@ -125,7 +125,7 @@ DefaultPlatform* DefaultPlatform::create(Backend* back
                 return new PlatformVkAndroid();
             #elif defined(IOS)
                 return new PlatformVkCocoaTouch();
-            #elif defined(__linux__)
+            #elif defined(__linux__) || defined(__FreeBSD__)
                 #if defined(FILAMENT_SUPPORTS_WAYLAND)
                     return new PlatformVkLinuxWayland();
                 #elif defined(FILAMENT_SUPPORTS_X11)
@@ -159,7 +159,7 @@ DefaultPlatform* DefaultPlatform::create(Backend* back
             return new PlatformCocoaTouchGL();
         #elif defined(__APPLE__)
             return new PlatformCocoaGL();
-        #elif defined(__linux__)
+        #elif defined(__linux__) || defined(__FreeBSD__)
             #if defined(FILAMENT_SUPPORTS_X11)
                 return new PlatformGLX();
             #elif defined(FILAMENT_SUPPORTS_EGL_ON_LINUX)
