--- src/glmid/glscript.h.orig	2008-03-02 14:07:01.000000000 -0500
+++ src/glmid/glscript.h	2008-03-02 14:07:39.000000000 -0500
@@ -32,6 +32,12 @@
 #include "gpsm.h"
 #include "swapfile.h"
 
+/* Check if we have guile of at least version 1.8 */
+#undef HAVE_GUILE18
+#if SCM_MAJOR_VERSION == 1 && SCM_MINOR_VERSION >= 8
+#define HAVE_GUILE18 1
+#endif
+
 
 /* Initializes the guile scripting subsystem. Returns 0 on success,
  * -1 on error. */
