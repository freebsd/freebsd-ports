--- ./src/coms/NetBuffer.cpp.orig	Sat Aug  6 13:57:39 2005
+++ ./src/coms/NetBuffer.cpp	Tue Aug  9 23:21:19 2005
@@ -20,7 +20,7 @@
 
 
 #include <coms/NetBuffer.h>
-#include <SDL/SDL_net.h>
+#include <SDL11/SDL_net.h>
 #include <string.h>
 
 NetBuffer NetBufferDefault::defaultBuffer;
