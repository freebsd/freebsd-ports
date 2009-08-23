--- src/drivers/audio/AudioChannel.cpp.orig	2007-11-15 00:42:05.000000000 +0100
+++ src/drivers/audio/AudioChannel.cpp	2008-11-16 01:55:40.000000000 +0100
@@ -26,7 +26,7 @@
 #include "../../common/global_private.h"
 #include "../../common/Thread.h" // needed for allocAlignedMem() and freeAlignedMem()
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 # include <stdlib.h>
 #else
 # include <malloc.h>
