--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/rSystem.h	Tue Feb 15 14:26:48 1994
+++ ./reuse/m2c/rSystem.h	Thu Aug  5 18:49:33 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_rSystem
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #define rSystem_cMaxFile	32
 #define rSystem_StdInput	0
 #define rSystem_StdOutput	1
@@ -12,11 +16,11 @@
 extern void rClose ARGS((rSystem_tFile File));
 extern BOOLEAN IsCharacterSpecial ARGS((rSystem_tFile File));
 extern ADDRESS rAlloc ARGS((LONGINT ByteCount));
-extern LONGINT rTime ARGS(());
-extern CARDINAL GetArgCount ARGS(());
+extern LONGINT rTime  ARGS((NOARGS));
+extern CARDINAL GetArgCount  ARGS((NOARGS));
 extern void GetArgument ARGS((INTEGER ArgNum, CHAR Argument[], LONGCARD ));
 extern void PutArgs ARGS((INTEGER Argc, ADDRESS Argv));
-extern INTEGER rErrNo ARGS(());
+extern INTEGER rErrNo  ARGS((NOARGS));
 extern INTEGER rSystem ARGS((CHAR String[], LONGCARD ));
 extern void rExit ARGS((INTEGER Status));
-extern void BEGIN_rSystem();
+extern void BEGIN_rSystem(NOARGS);
