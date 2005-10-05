--- src/core/compat-round.cc.orig	Wed Oct  5 21:18:30 2005
+++ src/core/compat-round.cc	Wed Oct  5 21:19:28 2005
@@ -43,7 +43,11 @@
 #define	COMPAT_FP_SUBNORMAL	0x08
 #define	COMPAT_FP_ZERO		0x10
 
+#ifdef Linux
 #include <endian.h>
+#elif defined(__FreeBSD__)
+#include <machine/endian.h>
+#endif
 #define	compat_fpclassify(x) \
     ((sizeof (x) == sizeof (float)) ? compat___fpclassifyf(x) \
      : (sizeof (x) == sizeof (double)) ? compat___fpclassifyd(x) \
