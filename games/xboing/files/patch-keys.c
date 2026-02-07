--- keys.c.orig	1996-11-22 01:28:46 UTC
+++ keys.c
@@ -105,7 +105,7 @@ static int endFrame = 0;
 static int startFrame = 0;
 enum KeysStates KeysState;
 static int waitingFrame;
-enum KeysStates waitMode;
+extern enum KeysStates waitMode;
 Pixmap mouse, leftarrow, rightarrow;
 Pixmap mouseM, leftarrowM, rightarrowM;
 
