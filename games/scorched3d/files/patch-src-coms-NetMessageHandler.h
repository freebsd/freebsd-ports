--- ./src/coms/NetMessageHandler.h.orig	Fri Jan 23 17:59:08 2004
+++ ./src/coms/NetMessageHandler.h	Fri Jan 23 18:02:10 2004
@@ -23,7 +23,7 @@
 #define __INCLUDE_NetMessageHandlerh_INCLUDE__
 
 #include <coms/NetMessage.h>
-#include <SDL/SDL_thread.h>
+#include <SDL11/SDL_thread.h>
 #include <list>
 
 class NetMessageHandlerI
