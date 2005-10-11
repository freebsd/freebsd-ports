--- ./src/coms/NetMessagePool.h.orig	Sat Aug  6 13:57:39 2005
+++ ./src/coms/NetMessagePool.h	Tue Aug  9 23:21:19 2005
@@ -24,7 +24,7 @@
 
 #include <coms/NetMessage.h>
 #include <list>
-#include <SDL/SDL_thread.h>
+#include <SDL11/SDL_thread.h>
 
 class NetMessagePool
 {
