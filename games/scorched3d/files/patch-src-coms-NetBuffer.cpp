--- ./src/coms/NetBuffer.cpp.orig	Wed Jun 30 18:35:46 2004
+++ ./src/coms/NetBuffer.cpp	Tue Jan 25 19:34:24 2005
@@ -20,7 +20,7 @@
 
 
 #include <coms/NetBuffer.h>
-#include <SDL/SDL_net.h>
+#include <SDL11/SDL_net.h>
 #include <string.h>
 
 NetBuffer NetBufferDefault::defaultBuffer;
