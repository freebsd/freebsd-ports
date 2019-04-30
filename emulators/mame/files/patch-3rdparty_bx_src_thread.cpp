--- 3rdparty/bx/src/thread.cpp.orig	2019-04-24 05:00:38 UTC
+++ 3rdparty/bx/src/thread.cpp
@@ -15,6 +15,7 @@
 	|| BX_PLATFORM_IOS     \
 	|| BX_PLATFORM_OSX     \
 	|| BX_PLATFORM_PS4     \
+	|| BX_PLATFORM_BSD     \
 	|| BX_PLATFORM_RPI
 #	include <pthread.h>
 #	if defined(__FreeBSD__)
