--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/DynArray.h	Tue Feb 15 14:26:47 1994
+++ ./reuse/m2c/DynArray.h	Thu Aug  5 18:49:33 2004
@@ -1,7 +1,11 @@
 #define DEFINITION_DynArray
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 extern void DynArray_MakeArray ARGS((ADDRESS *ArrayPtr, LONGINT *ElmtCount, LONGINT ElmtSize));
 extern void DynArray_ResizeArray ARGS((ADDRESS *ArrayPtr, LONGINT *OldElmtCount, LONGINT NewElmtCount, LONGINT ElmtSize));
 extern void DynArray_ExtendArray ARGS((ADDRESS *ArrayPtr, LONGINT *ElmtCount, LONGINT ElmtSize));
 extern void DynArray_ReleaseArray ARGS((ADDRESS *ArrayPtr, LONGINT *ElmtCount, LONGINT ElmtSize));
-extern void BEGIN_DynArray();
+extern void BEGIN_DynArray(NOARGS);
