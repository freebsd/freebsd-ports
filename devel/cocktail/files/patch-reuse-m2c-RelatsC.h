--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/RelatsC.h	Tue Feb 15 14:26:48 1994
+++ ./reuse/m2c/RelatsC.h	Thu Aug  5 18:49:33 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_RelatsC
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_IO
 #include "IO.h"
 #endif
@@ -57,4 +61,4 @@
 extern void RelatsC_WriteRelation ARGS((IO_tFile f, RelatsC_tRelation Rel));
 extern void RelatsC_Project1 ARGS((RelatsC_tRelation Rel, INTEGER e1, SetsC_tSet *Set));
 extern void RelatsC_Project2 ARGS((RelatsC_tRelation Rel, INTEGER e1, SetsC_tSet *Set));
-extern void BEGIN_RelatsC();
+extern void BEGIN_RelatsC(NOARGS);
