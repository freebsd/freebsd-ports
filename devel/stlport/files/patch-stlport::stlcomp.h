--- stlport/config/stlcomp.h.orig	Wed Jul 24 02:21:28 2002
+++ stlport/config/stlcomp.h	Wed Jul 24 02:21:16 2002
@@ -103,6 +103,9 @@
 # elif defined (__FCC_VERSION)
 /* Fujutsu Compiler, v4.0 assumed */
 #  include <config/stl_fujitsu.h>
+/* Intel(R) C++ Compiler */
+# elif defined (__ICC)
+#  include <config/stl_icc.h>
 # else
 /* Unable to identify the compiler, issue error diagnostic.
  * Edit <config/stl_mycomp.h> to set STLport up for your compiler. */
