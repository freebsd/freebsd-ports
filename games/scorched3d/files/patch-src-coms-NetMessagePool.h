--- ./src/coms/NetMessagePool.h.orig	Mon Nov 29 19:08:54 2004
+++ ./src/coms/NetMessagePool.h	Tue Jan 25 19:34:24 2005
@@ -24,7 +24,7 @@
 
 #include <coms/NetMessage.h>
 #include <list>
-#include <SDL/SDL_thread.h>
+#include <SDL11/SDL_thread.h>
 
 class NetMessagePool
 {
