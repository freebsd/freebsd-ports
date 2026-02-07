--- inst.c.orig	1996-11-22 01:28:46 UTC
+++ inst.c
@@ -107,7 +107,7 @@ static int endFrame = 0;
 static int nextFrame = 0;
 enum InstructStates InstructState;
 static int waitingFrame;
-enum InstructStates waitMode;
+extern enum InstructStates waitMode;
 
 #if NeedFunctionPrototypes
 void SetUpInstructions(Display *display, Window window, Colormap colormap)
