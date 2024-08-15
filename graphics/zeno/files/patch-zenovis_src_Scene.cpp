--- zenovis/src/Scene.cpp.orig	2024-04-22 12:39:31 UTC
+++ zenovis/src/Scene.cpp
@@ -12,7 +12,9 @@
 #include <zenovis/opengl/buffer.h>
 #include <zenovis/opengl/common.h>
 #include <zenovis/opengl/scope.h>
+#ifdef ZENO_ENABLE_OPTIX
 #include "../xinxinoptix/xinxinoptixapi.h"
+#endif
 #include <cstdlib>
 #include <map>
 
