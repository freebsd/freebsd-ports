--- stlport/config/stlcomp.h.orig	Sun Nov  2 16:59:12 2003
+++ stlport/config/stlcomp.h	Sat Nov  6 16:13:47 2004
@@ -109,6 +109,9 @@
 # elif defined (__FCC_VERSION)
 /* Fujutsu Compiler, v4.0 assumed */
 #  include <config/stl_fujitsu.h>
+# elif defined (__ICC)
+/* Intel(R) C++ Compiler */
+#  include <config/stl_icc.h>
 # elif defined(_CRAY)
 /* Cray C++ 3.4 or 3.5 */
 #  include <config/stl_cray.h>
