--- src/modules/graphics/opengl/Framebuffer.cpp.orig	2011-05-04 16:00:10 UTC
+++ src/modules/graphics/opengl/Framebuffer.cpp
@@ -1,3 +1,4 @@
+#define GL_GLEXT_PROTOTYPES
 #include "Framebuffer.h"
 #include <common/Matrix.h>
 
