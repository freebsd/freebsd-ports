--- irender/main.c.orig	Thu Dec 25 18:34:39 2003
+++ irender/main.c	Fri Mar 26 08:51:39 2004
@@ -12,9 +12,9 @@
 #include "parser.h"
 #include "config.h"
 
-#ifdef __FreeBSD__
-#include <floatingpoint.h>
-#endif
+#if (defined(__FreeBSD__) && defined(__i386__))
+#include <ieeefp.h>
+#endif /* __FreeBSD__ && __i386__ */
 
 /* Contains all configuration options. Subject to change by config file and  */
 /* and command line parameters.                                              */
@@ -48,16 +48,16 @@
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
 
+#if (defined(__FreeBSD__) && defined(__i386__))
+	fpsetmask(FP_X_INV | FP_X_DZ);
+#endif /* __FreeBSD__ && __i386__ */
+
     DoClipping = TRUE;
     GlblLastTime = IritCPUTime(FALSE);
     InitOptions();
@@ -129,10 +129,10 @@
     IRndrDestroy(Rend);
     TakeTime("Z-Buffer dump");
 
-#ifdef __FreeBSD__
+#if (defined(__FreeBSD__) && defined(__i386__))
     fpresetsticky(FP_X_INV | FP_X_OFL | FP_X_UFL |
 		  FP_X_DZ | FP_X_IMP | FP_X_DNML);
-#endif /* __FreeBSD__ */
+#endif /* __FreeBSD__ && __i386__ */
 
     return 0;
 }
