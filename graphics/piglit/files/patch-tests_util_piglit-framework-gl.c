--- tests/util/piglit-framework-gl.c.orig	2020-09-09 08:57:32 UTC
+++ tests/util/piglit-framework-gl.c
@@ -27,6 +27,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
+#ifdef __FreeBSD__
+#include <libgen.h>	/* For basename(3) */
+#endif
 
 #include "piglit-util-gl.h"
 #include "piglit-framework-gl/piglit_gl_framework.h"
