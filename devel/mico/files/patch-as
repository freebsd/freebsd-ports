--- os-math.h.orig	Mon May 26 14:55:46 2003
+++ include/mico/os-math.h	Tue Jun 24 02:20:33 2003
@@ -275,6 +275,21 @@
 };
 
 #else // neither _WIN32 nor _POCKET_PC
+#include <sys/param.h>
+#if (defined(__FreeBSD__) && __FreeBSD_version >= 500035)
+#ifndef fpclassify
+#define	fpclassify(x) \
+    ((sizeof (x) == sizeof (float)) ? __fpclassifyf(x) \
+    : (sizeof (x) == sizeof (double)) ? __fpclassifyd(x) \
+    : __fpclassifyl(x))
+#endif
+#ifndef isinf
+#define	isinf(x)	(fpclassify(x) == FP_INFINITE)
+#endif
+#ifndef isnan
+#define	isnan(x)	(fpclassify(x) == FP_NAN)
+#endif
+#endif
 
 #include <unistd.h>
 #include <signal.h>
