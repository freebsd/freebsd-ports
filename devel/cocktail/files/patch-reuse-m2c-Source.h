--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Source.h	Tue Feb 15 14:27:00 1994
+++ ./reuse/m2c/Source.h	Thu Aug  5 18:49:34 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_Source
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_rSystem
 #include "rSystem.h"
 #endif
@@ -7,4 +11,4 @@
 extern rSystem_tFile Source_BeginSource ARGS((CHAR FileName[], LONGCARD ));
 extern INTEGER Source_GetLine ARGS((rSystem_tFile File, ADDRESS Buffer, CARDINAL Size));
 extern void Source_CloseSource ARGS((rSystem_tFile File));
-extern void BEGIN_Source();
+extern void BEGIN_Source(NOARGS);
