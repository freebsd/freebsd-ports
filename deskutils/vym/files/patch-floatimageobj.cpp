--- floatimageobj.cpp.orig	Sun Sep 26 22:45:56 2004
+++ floatimageobj.cpp	Sun Oct 17 17:12:27 2004
@@ -2,6 +2,12 @@
 #include "branchobj.h"
 #include <math.h>
 
+#if !defined(HAVE_LRINTF)
+static inline long int lrint(double x)
+{
+    return (long)(rint(x));
+}
+#endif
 
 /////////////////////////////////////////////////////////////////
 // FloatImageObj
