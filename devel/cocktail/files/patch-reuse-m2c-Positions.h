--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Positions.h	Tue Feb 15 14:26:49 1994
+++ ./reuse/m2c/Positions.h	Thu Aug  5 18:49:33 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_Positions
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_IO
 #include "IO.h"
 #endif
@@ -11,4 +15,4 @@
 extern INTEGER Positions_Compare ARGS((Positions_tPosition Position1, Positions_tPosition Position2));
 extern void Positions_WritePosition ARGS((IO_tFile File, Positions_tPosition Position));
 extern void Positions_ReadPosition ARGS((IO_tFile File, Positions_tPosition *Position));
-extern void BEGIN_Positions();
+extern void BEGIN_Positions(NOARGS);
