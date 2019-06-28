--- src/Loader.cpp.orig	2018-03-24 23:40:31 UTC
+++ src/Loader.cpp
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
