--- src/coms/NetClient.cpp.orig	Wed Jul 30 17:41:25 2003
+++ src/coms/NetClient.cpp	Sun Aug  3 09:07:12 2003
@@ -24,7 +24,7 @@
 #include <coms/NetMessageHandler.h>
 #include <coms/NetMessagePool.h>
 #include <common/Logger.h>
-#include <SDL/SDL_thread.h>
+#include <SDL11/SDL_thread.h>
 
 NetClient *NetClient::instance_ = 0;
 
