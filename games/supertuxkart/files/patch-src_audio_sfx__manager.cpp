--- src/audio/sfx_manager.cpp.orig	2015-04-21 11:32:23 UTC
+++ src/audio/sfx_manager.cpp
@@ -28,6 +28,7 @@
 #include <pthread.h>
 #include <stdexcept>
 #include <algorithm>
+#include <cerrno>
 #include <map>
 
 #include <stdio.h>
