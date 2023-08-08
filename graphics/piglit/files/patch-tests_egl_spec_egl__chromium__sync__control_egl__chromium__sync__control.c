--- tests/egl/spec/egl_chromium_sync_control/egl_chromium_sync_control.c.orig	2020-09-09 08:57:32 UTC
+++ tests/egl/spec/egl_chromium_sync_control/egl_chromium_sync_control.c
@@ -35,6 +35,9 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <time.h>
+#ifdef __FreeBSD__
+#include <libgen.h>	/* For basename(3) */
+#endif
 
 #include "piglit-util-egl.h"
 #include "piglit-util-gl.h"
