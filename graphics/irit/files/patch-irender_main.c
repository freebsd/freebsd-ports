--- irender/main.c.orig	Mon Feb  2 13:53:42 2004
+++ irender/main.c	Mon Feb  2 14:05:03 2004
@@ -13,7 +13,7 @@
 #include "config.h"
 
 #ifdef __FreeBSD__
-#include <floatingpoint.h>
+#include <ieeefp.h>
 #endif
 
 /* Contains all configuration options. Subject to change by config file and  */
@@ -48,15 +48,15 @@
 *****************************************************************************/
 int main(int argc, char *argv[])
 {
-#ifdef __FreeBSD__
-    fpsetmask(FP_X_INV | FP_X_DZ);
-#endif /* __FreeBSD__ */
-
     IPObjectStruct *Objects, *MatrixObjects;
     char *BaseDirectory,
 	*MatrixFiles[] = {NULL, NULL};
     IRndrPtrType Rend;
     BoolType DoClipping;
+
+#ifdef __FreeBSD__
+	fpsetmask(FP_X_INV | FP_X_DZ);
+#endif /* __FreeBSD__ */
 
     DoClipping = TRUE;
     GlblLastTime = IritCPUTime(FALSE);
