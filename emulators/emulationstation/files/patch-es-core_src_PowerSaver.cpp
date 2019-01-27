Fix compiler error (missing include)

--- es-core/src/PowerSaver.cpp.orig	2018-08-11 01:13:24 UTC
+++ es-core/src/PowerSaver.cpp
@@ -2,6 +2,7 @@
 
 #include "AudioManager.h"
 #include "Settings.h"
+#include <string>
 
 bool PowerSaver::mState = false;
 bool PowerSaver::mRunningScreenSaver = false;
