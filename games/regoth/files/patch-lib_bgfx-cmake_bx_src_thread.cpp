--- lib/bgfx-cmake/bx/src/thread.cpp.orig	2018-04-24 22:27:07 UTC
+++ lib/bgfx-cmake/bx/src/thread.cpp
@@ -7,6 +7,7 @@
 
 #if    BX_PLATFORM_ANDROID \
 	|| BX_PLATFORM_LINUX   \
+	|| BX_PLATFORM_BSD     \
 	|| BX_PLATFORM_IOS     \
 	|| BX_PLATFORM_OSX     \
 	|| BX_PLATFORM_PS4     \
