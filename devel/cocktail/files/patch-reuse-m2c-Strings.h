--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Strings.h	Tue Feb 15 14:26:52 1994
+++ ./reuse/m2c/Strings.h	Thu Aug  5 18:49:33 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_Strings
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_IO
 #include "IO.h"
 #endif
@@ -32,4 +36,4 @@
 extern void Strings_ReadL ARGS((IO_tFile f, Strings_tString *s));
 extern void Strings_WriteS ARGS((IO_tFile f, Strings_tString *s));
 extern void Strings_WriteL ARGS((IO_tFile f, Strings_tString *s));
-extern void BEGIN_Strings();
+extern void BEGIN_Strings(NOARGS);
