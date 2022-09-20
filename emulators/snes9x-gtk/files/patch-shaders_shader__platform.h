--- shaders/shader_platform.h.orig	2022-09-19 23:41:19 UTC
+++ shaders/shader_platform.h
@@ -8,6 +8,7 @@
 #define __SHADER_PLATFORM_H
 
 #include "port.h"
+#include <unistd.h>
 
 #ifdef SNES9X_GTK
 #include <epoxy/gl.h>
