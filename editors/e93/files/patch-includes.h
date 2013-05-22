--- includes.h.orig	2013-05-22 09:36:16.000000000 +0200
+++ includes.h	2013-05-22 09:42:02.000000000 +0200
@@ -29,6 +29,9 @@
 #include	<locale.h>
 
 #include	<tcl.h>
+#if (TCL_MAJOR_VERSION < 8) || (TCL_MAJOR_VERSION == 8) && (TCL_MINOR_VERSION < 6)
+#define Tcl_GetErrorLine(interp) (interp->errorLine)
+#endif
 
 #include	"defines.h"
 #include	"guidefs.h"
