https://github.com/spring/spring/pull/557

--- rts/builds/dedicated/main.cpp.orig	2020-12-26 12:45:43 UTC
+++ rts/builds/dedicated/main.cpp
@@ -4,6 +4,8 @@
 
 #ifdef _WIN32
 #include <windows.h>
+#else
+#include <unistd.h>
 #endif
 
 #include "Game/GameSetup.h"
