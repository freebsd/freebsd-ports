--- ./src/client/ClientMain.cpp.orig	Sat Aug  6 13:57:39 2005
+++ ./src/client/ClientMain.cpp	Tue Aug  9 23:21:17 2005
@@ -70,7 +70,7 @@
 #include <common/Gamma.h>
 #include <common/Clock.h>
 #include <sound/Sound.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 static int mouseEventCount = 0;
 static bool paused = false;
