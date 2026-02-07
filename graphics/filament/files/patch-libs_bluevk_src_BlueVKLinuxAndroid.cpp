--- libs/bluevk/src/BlueVKLinuxAndroid.cpp.orig	2022-08-18 16:44:25 UTC
+++ libs/bluevk/src/BlueVKLinuxAndroid.cpp
@@ -42,7 +42,7 @@ bool loadLibrary() {
         path = FILAMENT_VKLIBRARY_PATH;
 #elif defined(__ANDROID__)
         path = "libvulkan.so";
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
         path = "libvulkan.so.1";
 #else
 #error "This file should only be compiled for Android or Linux"
