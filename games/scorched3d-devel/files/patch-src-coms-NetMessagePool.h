--- ./src/coms/NetMessagePool.h.orig	Fri Jan 23 17:59:08 2004
+++ ./src/coms/NetMessagePool.h	Fri Jan 23 18:02:11 2004
@@ -24,7 +24,7 @@
 
 #include <coms/NetMessage.h>
 #include <list>
-#include <SDL/SDL_thread.h>
+#include <SDL11/SDL_thread.h>
 
 class NetMessagePool
 {
