--- src/client/ClientMain.cpp.orig	Wed Jul 30 17:41:23 2003
+++ src/client/ClientMain.cpp	Sun Aug  3 09:07:11 2003
@@ -35,7 +35,7 @@
 #include <coms/NetClient.h>
 #include <engine/MainLoop.h>
 #include <engine/GameState.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 void clientCleanup()
 {
