--- demo.c.orig	1996-11-22 01:28:46 UTC
+++ demo.c
@@ -107,7 +107,7 @@ static int endFrame = 0;
 static int startFrame = 0;
 enum DemoStates DemoState;
 static int waitingFrame;
-enum DemoStates waitMode;
+extern enum DemoStates waitMode;
 
 #if NeedFunctionPrototypes
 void SetUpDemonstration(Display *display, Window window, Colormap colormap)
@@ -154,7 +154,7 @@ static void DoBlocks(display, window)
 
     /* Construct the demo level filename */
     if ((str = getenv("XBOING_LEVELS_DIR")) != NULL)
-        sprintf(levelPath, "%s/demo.data", str);
+        snprintf(levelPath, sizeof(levelPath),"%s/demo.data", str);
     else
         sprintf(levelPath, "%s/demo.data", LEVEL_INSTALL_DIR);
 
