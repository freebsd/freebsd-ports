--- ./src/client/ClientMain.cpp.orig	Fri May 28 00:24:45 2004
+++ ./src/client/ClientMain.cpp	Sun May 30 22:43:47 2004
@@ -66,7 +66,7 @@
 #include <common/Gamma.h>
 #include <common/Sound.h>
 #include <common/Clock.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 bool initHardware(ProgressCounter *progressCounter)
 {
