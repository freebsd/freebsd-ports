--- src/coms/NetBuffer.cpp.orig	Wed Jul 30 17:41:25 2003
+++ src/coms/NetBuffer.cpp	Sun Aug  3 09:07:12 2003
@@ -20,7 +20,7 @@
 
 
 #include <coms/NetBuffer.h>
-#include <SDL/SDL_net.h>
+#include <SDL11/SDL_net.h>
 #include <string.h>
 
 NetBuffer NetBufferDefault::defaultBuffer;
