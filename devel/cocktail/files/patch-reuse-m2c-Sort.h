--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Sort.h	Tue Feb 15 14:27:00 1994
+++ ./reuse/m2c/Sort.h	Thu Aug  5 18:49:34 2004
@@ -1,6 +1,10 @@
 #define DEFINITION_Sort
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 typedef BOOLEAN (*Sort_tProcIntIntBool) ARGS((INTEGER, INTEGER));
 typedef void (*Sort_tProcIntInt) ARGS((INTEGER, INTEGER));
 extern void Sort_Sort ARGS((INTEGER Lwb, INTEGER Upb, Sort_tProcIntIntBool IsLess, Sort_tProcIntInt Swap));
-extern void BEGIN_Sort();
+extern void BEGIN_Sort(NOARGS);
