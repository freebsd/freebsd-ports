--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/StringMem.h	Tue Feb 15 14:26:52 1994
+++ ./reuse/m2c/StringMem.h	Thu Aug  5 18:49:33 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_StringMem
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_IO
 #include "IO.h"
 #endif
@@ -14,6 +18,6 @@
 extern CARDINAL StringMem_Length ARGS((StringMem_tStringRef r));
 extern BOOLEAN StringMem_IsEqual ARGS((StringMem_tStringRef r, Strings_tString *s));
 extern void StringMem_WriteString ARGS((IO_tFile f, StringMem_tStringRef r));
-extern void StringMem_WriteStringMemory ARGS(());
-extern void StringMem_InitStringMemory ARGS(());
-extern void BEGIN_StringMem();
+extern void StringMem_WriteStringMemory  ARGS((NOARGS));
+extern void StringMem_InitStringMemory  ARGS((NOARGS));
+extern void BEGIN_StringMem(NOARGS);
