--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Sets.h	Tue Feb 15 14:26:57 1994
+++ ./reuse/m2c/Sets.h	Thu Aug  5 18:49:34 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_Sets
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_IO
 #include "IO.h"
 #endif
@@ -7,6 +11,7 @@
 typedef struct Sets_1 {
     BITSET A[1000000 + 1];
 } Sets_ArrayOfBitset;
+
 typedef void (*Sets_ProcOfCard) ARGS((CARDINAL));
 typedef BOOLEAN (*Sets_ProcOfCardToBool) ARGS((CARDINAL));
 typedef Sets_ArrayOfBitset *Sets_PointerToArray;
@@ -47,4 +52,4 @@
 extern void Sets_ForallDo ARGS((Sets_tSet Set, Sets_ProcOfCard Proc));
 extern void Sets_ReadSet ARGS((IO_tFile f, Sets_tSet *Set));
 extern void Sets_WriteSet ARGS((IO_tFile f, Sets_tSet Set));
-extern void BEGIN_Sets();
+extern void BEGIN_Sets(NOARGS);
