--- src/glmid/glscript.h.orig	2004-10-23 13:09:23 UTC
+++ src/glmid/glscript.h
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
