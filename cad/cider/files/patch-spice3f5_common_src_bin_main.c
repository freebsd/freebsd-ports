--- spice3f5/common/src/bin/main.c.orig	1994-03-12 08:22:28 UTC
+++ spice3f5/common/src/bin/main.c
@@ -36,6 +36,11 @@ Author: 1985 Wayne A. Christopher
 #endif
 
 #include "patchlev.h"
+
+#ifdef __FreeBSD__
+#include <ieeefp.h>
+#endif
+
 #include "suffix.h"
 
 /* (Virtual) Machine architecture parameters */
@@ -216,6 +221,10 @@ main(ac, av)
 
 #endif
 
+#ifdef __FreeBSD__
+    fpsetmask(fpgetmask() & ~FP_X_INV & ~FP_X_DZ & ~FP_X_OFL);
+#endif
+
     /* MFB tends to jump to 0 on errors.  This tends to catch it. */
     if (started) {
         fprintf(cp_err, "main: Internal Error: jump to zero\n");
