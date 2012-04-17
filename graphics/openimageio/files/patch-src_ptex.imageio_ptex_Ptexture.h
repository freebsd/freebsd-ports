--- ptex.imageio/ptex/Ptexture.h.orig	2012-03-30 22:01:12.000000000 +1030
+++ ptex.imageio/ptex/Ptexture.h	2012-03-30 22:01:35.000000000 +1030
@@ -41,6 +41,14 @@
   @brief Public API classes for reading, writing, caching, and filtering Ptex files.
 */
 
+#include "fmath.h"
+
+#if !defined(log2)
+
+inline double log2(double x) {return log(x)*(double)1.4426950408889634;}
+
+#endif /* log2 */
+
 #if defined(_WIN32) || defined(_WINDOWS) || defined(_MSC_VER)
 # ifndef PTEXAPI
 #  ifndef PTEX_STATIC
