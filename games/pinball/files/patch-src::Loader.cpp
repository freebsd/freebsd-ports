--- ./src/Loader.cpp.orig	Thu Nov 20 17:46:17 2003
+++ ./src/Loader.cpp	Fri Dec 12 21:31:48 2003
@@ -17,6 +17,7 @@
 #include <iostream>
 
 #include "Private.h"
+#include "Config.h"
 #include "Loader.h"
 #include "Pinball.h"
 #include "Keyboard.h"
@@ -39,7 +40,6 @@
 #include "SoundUtil.h"
 #include "Score.h"
 #include "StdAnimation.h"
-#include "Config.h"
 #include "StateBehavior.h"
 #include "Script.h"
 #include "FakeModuleBehavior.h"
