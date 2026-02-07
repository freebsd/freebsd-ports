--- renderer/rb_qgl.h.orig	Mon Jul 24 15:09:29 2006
+++ renderer/rb_qgl.h	Mon Jul 24 15:14:03 2006
@@ -34,8 +34,10 @@
 # include <GL/glx.h>
 #endif
 
+#if 0
 typedef int GLsizeiptrARB;
 typedef int GLintptrARB;
+#endif
 
 #ifndef APIENTRY
 # define APIENTRY
