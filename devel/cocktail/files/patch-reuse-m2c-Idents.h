--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Idents.h	Tue Feb 15 14:26:53 1994
+++ ./reuse/m2c/Idents.h	Thu Aug  5 18:49:33 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_Idents
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_IO
 #include "IO.h"
 #endif
@@ -17,9 +21,9 @@
 extern Idents_tIdent Idents_MakeIdent ARGS((Strings_tString *s));
 extern void Idents_GetString ARGS((Idents_tIdent i, Strings_tString *s));
 extern StringMem_tStringRef Idents_GetStringRef ARGS((Idents_tIdent i));
-extern Idents_tIdent Idents_MaxIdent ARGS(());
+extern Idents_tIdent Idents_MaxIdent  ARGS((NOARGS));
 extern void Idents_WriteIdent ARGS((IO_tFile f, Idents_tIdent i));
-extern void Idents_WriteIdents ARGS(());
-extern void Idents_InitIdents ARGS(());
-extern void Idents_WriteHashTable ARGS(());
-extern void BEGIN_Idents();
+extern void Idents_WriteIdents  ARGS((NOARGS));
+extern void Idents_InitIdents  ARGS((NOARGS));
+extern void Idents_WriteHashTable  ARGS((NOARGS));
+extern void BEGIN_Idents(NOARGS);
