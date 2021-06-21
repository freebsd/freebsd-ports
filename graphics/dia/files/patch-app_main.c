--- app/main.c.orig	2014-08-24 15:44:07 UTC
+++ app/main.c
@@ -17,12 +17,20 @@
  */
 #include <config.h>
 
+#if defined(FP_X_INV) && defined(FP_X_DZ)
+#include <ieeefp.h>
+#endif
+
 #include "app_procs.h"
 
 #include "interface.h"
 
 int main(int argc, char *argv[])
 {
+#if defined(FP_X_INV) && defined(FP_X_DZ)
+  fpsetmask(0);
+#endif
+
   app_init(argc, argv);
 
   if (!app_is_interactive())
