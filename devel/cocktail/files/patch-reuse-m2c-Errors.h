--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Errors.h	Tue Feb 15 14:26:49 1994
+++ ./reuse/m2c/Errors.h	Thu Aug  5 18:49:33 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_Errors
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_Positions
 #include "Positions.h"
 #endif
@@ -42,4 +46,4 @@
 extern void Errors_Message ARGS((CHAR ErrorText[], LONGCARD , CARDINAL ErrorClass, Positions_tPosition Position));
 extern void Errors_MessageI ARGS((CHAR ErrorText[], LONGCARD , CARDINAL ErrorClass, Positions_tPosition Position, CARDINAL InfoClass, ADDRESS Info));
 extern void Errors_WriteMessages ARGS((IO_tFile File));
-extern void BEGIN_Errors();
+extern void BEGIN_Errors(NOARGS);
