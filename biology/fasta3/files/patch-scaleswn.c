--- scaleswn.c.orig	Thu Aug 22 20:30:55 2002
+++ scaleswn.c	Thu Aug 22 20:31:06 2002
@@ -26,7 +26,7 @@
 #include <math.h>
 #include <string.h>
 
-#if !defined(__MWERKS__) && !defined(MacOSX)
+#if !defined(__FreeBSD__) && !defined(__MWERKS__) && !defined(MacOSX)
 #include <values.h>
 #else
 #include <limits.h>	/* needed for LONG_MAX */
