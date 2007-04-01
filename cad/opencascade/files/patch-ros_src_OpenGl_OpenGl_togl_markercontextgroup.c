--- ./ros/src/OpenGl/OpenGl_togl_markercontextgroup.c.orig	Thu Apr 21 15:09:02 2005
+++ ./ros/src/OpenGl/OpenGl_togl_markercontextgroup.c	Sun Jul  2 07:03:39 2006
@@ -39,7 +39,11 @@
 
 #include <GL/gl.h>
 #include <GL/glu.h>
-#include <malloc.h>
+#ifdef __FreeBSD__
+# include <stdlib.h>
+#else
+# include <malloc.h>
+#endif
 
 typedef struct
 {
