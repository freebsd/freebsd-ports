--- ./src/common/Clock.cpp.orig	Fri Jan 23 17:59:03 2004
+++ ./src/common/Clock.cpp	Fri Jan 23 18:01:54 2004
@@ -20,7 +20,7 @@
 
 #include <common/Defines.h>
 #include <common/Clock.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 Clock::Clock() : isPaused_(false)
 {
