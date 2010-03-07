--- simgear/compiler.h.orig	2010-02-25 09:07:12.998305929 +0000
+++ simgear/compiler.h	2010-02-25 09:07:20.148299853 +0000
@@ -149,14 +149,6 @@
 #  endif
 #endif
 
-#if defined (__FreeBSD__)
-#  if __FreeBSD_version < 500000
-     extern "C" {
-       inline int isnan(double r) { return !(r <= 0 || r >= 0); }
-     }
-#  endif
-#endif
-
 #if defined (__CYGWIN__)
 #  include <ieeefp.h>		// isnan
 #endif
