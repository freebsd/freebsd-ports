--- eval.c.orig	Wed Feb 23 15:54:03 2005
+++ eval.c	Wed Feb 23 15:54:18 2005
@@ -12,6 +12,10 @@
 
 **********************************************************************/
 
+#ifdef _THREAD_SAFE
+#undef _THREAD_SAFE
+#endif
+
 #include "ruby.h"
 #include "node.h"
 #include "env.h"
