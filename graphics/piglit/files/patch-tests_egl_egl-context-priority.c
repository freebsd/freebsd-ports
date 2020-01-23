--- tests/egl/egl-context-priority.c.orig	2019-12-26 13:24:57 UTC
+++ tests/egl/egl-context-priority.c
@@ -24,6 +24,10 @@
 #include "piglit-util-egl.h"
 #include "piglit-util-gl.h"
 
+#ifndef EGL_NO_CONFIG_MESA
+#define EGL_NO_CONFIG_MESA                   ((EGLConfig)0)
+#endif
+
 /**
  * @file egl-context-priority.c
  *
