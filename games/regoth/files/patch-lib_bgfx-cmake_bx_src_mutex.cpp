--- lib/bgfx-cmake/bx/src/mutex.cpp.orig	2018-04-24 22:16:50 UTC
+++ lib/bgfx-cmake/bx/src/mutex.cpp
@@ -9,6 +9,7 @@
 
 #if    BX_PLATFORM_ANDROID \
 	|| BX_PLATFORM_LINUX   \
+	|| BX_PLATFORM_BSD     \
 	|| BX_PLATFORM_IOS     \
 	|| BX_PLATFORM_OSX     \
 	|| BX_PLATFORM_PS4     \
