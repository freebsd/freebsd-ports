--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Lists.h	Tue Feb 15 14:26:54 1994
+++ ./reuse/m2c/Lists.h	Thu Aug  5 18:49:34 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_Lists
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_IO
 #include "IO.h"
 #endif
@@ -24,4 +28,4 @@
 extern BOOLEAN Lists_IsEmpty ARGS((Lists_tList List));
 extern CARDINAL Lists_Length ARGS((Lists_tList List));
 extern void Lists_WriteList ARGS((IO_tFile f, Lists_tList List, Lists_tProcOfFileAddress Proc));
-extern void BEGIN_Lists();
+extern void BEGIN_Lists(NOARGS);
