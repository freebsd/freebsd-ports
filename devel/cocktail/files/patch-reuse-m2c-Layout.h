--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Layout.h	Tue Feb 15 14:26:53 1994
+++ ./reuse/m2c/Layout.h	Thu Aug  5 18:49:33 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_Layout
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_IO
 #include "IO.h"
 #endif
@@ -10,4 +14,4 @@
 extern void Layout_ReadSpace ARGS((IO_tFile f));
 extern void Layout_ReadSpaces ARGS((IO_tFile f, INTEGER Count));
 extern void Layout_SkipSpaces ARGS((IO_tFile f));
-extern void BEGIN_Layout();
+extern void BEGIN_Layout(NOARGS);
