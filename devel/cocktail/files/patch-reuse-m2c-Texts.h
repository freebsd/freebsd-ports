--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Texts.h	Tue Feb 15 14:27:03 1994
+++ ./reuse/m2c/Texts.h	Thu Aug  5 18:49:34 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_Texts
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_IO
 #include "IO.h"
 #endif
@@ -18,4 +22,4 @@
 extern void Texts_Insert ARGS((Texts_tText *Text, Strings_tString *String));
 extern BOOLEAN Texts_IsEmpty ARGS((Texts_tText *Text));
 extern void Texts_WriteText ARGS((IO_tFile f, Texts_tText Text));
-extern void BEGIN_Texts();
+extern void BEGIN_Texts(NOARGS);
