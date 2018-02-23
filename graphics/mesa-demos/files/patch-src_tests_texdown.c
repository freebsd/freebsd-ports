# aligned_alloc() is in <stdlib.h>, so only _aligned_malloc() needs <malloc.h>
#
--- src/tests/texdown.c.orig	2018-02-23 08:50:21 UTC
+++ src/tests/texdown.c
@@ -34,7 +34,9 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#ifdef _WIN32
 #include <malloc.h>
+#endif
 #include <math.h>
 #include <GL/glew.h>
 #include "glut_wrap.h"
