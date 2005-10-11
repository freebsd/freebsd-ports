--- ./src/coms/NetMessageHandler.h.orig	Sat Aug  6 13:57:39 2005
+++ ./src/coms/NetMessageHandler.h	Tue Aug  9 23:21:19 2005
@@ -23,7 +23,7 @@
 #define __INCLUDE_NetMessageHandlerh_INCLUDE__
 
 #include <coms/NetMessage.h>
-#include <SDL/SDL_thread.h>
+#include <SDL11/SDL_thread.h>
 #include <list>
 
 class NetMessageHandlerI
