--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/IO.h	Tue Feb 15 14:26:49 1994
+++ ./reuse/m2c/IO.h	Thu Aug  5 18:49:33 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_IO
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_rSystem
 #include "rSystem.h"
 #endif
@@ -38,5 +42,5 @@
 extern void IO_WriteLong ARGS((IO_tFile f, LONGINT n, CARDINAL FieldWidth));
 extern void IO_WriteCard ARGS((IO_tFile f, CARDINAL n, CARDINAL FieldWidth));
 extern void IO_WriteNl ARGS((IO_tFile f));
-extern void IO_CloseIO ARGS(());
-extern void BEGIN_IO();
+extern void IO_CloseIO  ARGS((NOARGS));
+extern void BEGIN_IO(NOARGS);
