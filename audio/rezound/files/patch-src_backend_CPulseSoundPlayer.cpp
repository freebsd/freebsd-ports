--- src/backend/CPulseSoundPlayer.cpp.orig	2013-12-27 03:54:12 UTC
+++ src/backend/CPulseSoundPlayer.cpp
@@ -30,6 +30,8 @@ using namespace std;
 #include <pulse/simple.h>
 #include <pulse/error.h>
 
+#include <TAutoBuffer.h>
+
 #include "settings.h"
 
 #define BUFFER_COUNT gDesiredOutputBufferCount
