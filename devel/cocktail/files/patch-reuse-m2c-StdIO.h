--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/StdIO.h	Tue Feb 15 14:27:01 1994
+++ ./reuse/m2c/StdIO.h	Thu Aug  5 18:49:34 2004
@@ -1,22 +1,26 @@
 #define DEFINITION_StdIO
 
-extern void StdIO_ReadClose ARGS(());
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
+extern void StdIO_ReadClose  ARGS((NOARGS));
 extern INTEGER StdIO_Read ARGS((ADDRESS Buffer, CARDINAL Size));
-extern CHAR StdIO_ReadC ARGS(());
-extern INTEGER StdIO_ReadI ARGS(());
-extern REAL StdIO_ReadR ARGS(());
-extern BOOLEAN StdIO_ReadB ARGS(());
+extern CHAR StdIO_ReadC  ARGS((NOARGS));
+extern INTEGER StdIO_ReadI  ARGS((NOARGS));
+extern REAL StdIO_ReadR  ARGS((NOARGS));
+extern BOOLEAN StdIO_ReadB  ARGS((NOARGS));
 extern INTEGER StdIO_ReadN ARGS((INTEGER Base));
 extern void StdIO_ReadS ARGS((CHAR s[], LONGCARD ));
-extern SHORTINT StdIO_ReadShort ARGS(());
-extern LONGINT StdIO_ReadLong ARGS(());
-extern CARDINAL StdIO_ReadCard ARGS(());
-extern void StdIO_ReadNl ARGS(());
-extern void StdIO_UnRead ARGS(());
-extern BOOLEAN StdIO_EndOfLine ARGS(());
-extern BOOLEAN StdIO_EndOfFile ARGS(());
-extern void StdIO_WriteClose ARGS(());
-extern void StdIO_WriteFlush ARGS(());
+extern SHORTINT StdIO_ReadShort  ARGS((NOARGS));
+extern LONGINT StdIO_ReadLong  ARGS((NOARGS));
+extern CARDINAL StdIO_ReadCard  ARGS((NOARGS));
+extern void StdIO_ReadNl  ARGS((NOARGS));
+extern void StdIO_UnRead  ARGS((NOARGS));
+extern BOOLEAN StdIO_EndOfLine  ARGS((NOARGS));
+extern BOOLEAN StdIO_EndOfFile  ARGS((NOARGS));
+extern void StdIO_WriteClose  ARGS((NOARGS));
+extern void StdIO_WriteFlush  ARGS((NOARGS));
 extern INTEGER StdIO_Write ARGS((ADDRESS Buffer, CARDINAL Size));
 extern void StdIO_WriteC ARGS((CHAR c));
 extern void StdIO_WriteI ARGS((INTEGER n, CARDINAL FieldWidth));
@@ -27,6 +31,6 @@
 extern void StdIO_WriteShort ARGS((SHORTINT n, CARDINAL FieldWidth));
 extern void StdIO_WriteLong ARGS((LONGINT n, CARDINAL FieldWidth));
 extern void StdIO_WriteCard ARGS((CARDINAL n, CARDINAL FieldWidth));
-extern void StdIO_WriteNl ARGS(());
-extern void StdIO_CloseIO ARGS(());
-extern void BEGIN_StdIO();
+extern void StdIO_WriteNl  ARGS((NOARGS));
+extern void StdIO_CloseIO  ARGS((NOARGS));
+extern void BEGIN_StdIO(NOARGS);
