--- Mercator/iround.h.orig	Tue Oct  4 01:25:06 2005
+++ Mercator/iround.h	Tue Oct  4 01:31:36 2005
@@ -9,6 +9,17 @@
 #error iround.h must be included after config.h
 #endif
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version < 500000
+extern "C" {
+extern float fabsf __P((float));
+extern float rintf __P((float));
+}
+#endif
+#include <cmath>
+#endif
+
 #ifdef HAVE_LRINTF
     #define I_ROUND(x) (::lrintf(x)) 
 #elif defined(HAVE_RINTF)
