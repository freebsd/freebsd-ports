--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Relations.h	Tue Feb 15 14:26:58 1994
+++ ./reuse/m2c/Relations.h	Thu Aug  5 18:49:34 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_Relations
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_IO
 #include "IO.h"
 #endif
@@ -58,4 +62,4 @@
 extern void Relations_WriteRelation ARGS((IO_tFile f, Relations_tRelation Rel));
 extern void Relations_Project1 ARGS((Relations_tRelation Rel, INTEGER e1, Sets_tSet *Set));
 extern void Relations_Project2 ARGS((Relations_tRelation Rel, INTEGER e1, Sets_tSet *Set));
-extern void BEGIN_Relations();
+extern void BEGIN_Relations(NOARGS);
