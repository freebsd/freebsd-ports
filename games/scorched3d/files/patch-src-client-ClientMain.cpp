--- ./src/client/ClientMain.cpp.orig	Mon Nov 29 19:08:50 2004
+++ ./src/client/ClientMain.cpp	Tue Jan 25 19:34:20 2005
@@ -71,7 +71,7 @@
 #include <common/Gamma.h>
 #include <common/Sound.h>
 #include <common/Clock.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 bool initHardware(ProgressCounter *progressCounter)
 {
