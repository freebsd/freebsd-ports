--- util/gaul/gaul_util.h.orig	Fri Oct 31 10:06:41 2003
+++ util/gaul/gaul_util.h	Fri Oct 31 10:06:52 2003
@@ -103,7 +103,7 @@
 /*
  * Define boolean type sensibly.
  */
-#if HAVE_STDBOOL_H != 1
+#if HAVE_STDBOOL_H == 1
 # include <stdbool.h>
 #else
 
