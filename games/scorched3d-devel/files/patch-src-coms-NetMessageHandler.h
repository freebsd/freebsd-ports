--- ./src/coms/NetMessageHandler.h.orig	Thu Sep 18 22:28:06 2003
+++ ./src/coms/NetMessageHandler.h	Tue Jan 25 19:34:24 2005
@@ -23,7 +23,7 @@
 #define __INCLUDE_NetMessageHandlerh_INCLUDE__
 
 #include <coms/NetMessage.h>
-#include <SDL/SDL_thread.h>
+#include <SDL11/SDL_thread.h>
 #include <list>
 
 class NetMessageHandlerI
