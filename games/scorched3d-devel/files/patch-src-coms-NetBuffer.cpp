--- ./src/coms/NetBuffer.cpp.orig	Fri Jan 23 17:59:07 2004
+++ ./src/coms/NetBuffer.cpp	Fri Jan 23 18:02:08 2004
@@ -20,7 +20,7 @@
 
 
 #include <coms/NetBuffer.h>
-#include <SDL/SDL_net.h>
+#include <SDL11/SDL_net.h>
 #include <string.h>
 
 NetBuffer NetBufferDefault::defaultBuffer;
