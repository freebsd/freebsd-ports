--- 3rdparty/bx/src/mutex.cpp.orig	2019-04-24 05:00:38 UTC
+++ 3rdparty/bx/src/mutex.cpp
@@ -16,6 +16,7 @@
 	|| BX_PLATFORM_IOS     \
 	|| BX_PLATFORM_OSX     \
 	|| BX_PLATFORM_PS4     \
+	|| BX_PLATFORM_BSD     \
 	|| BX_PLATFORM_RPI
 #	include <pthread.h>
 #elif  BX_PLATFORM_WINDOWS \
