--- preview.c.orig	1996-11-22 01:28:46 UTC
+++ preview.c
@@ -102,7 +102,7 @@ void DoPreviewWait();
 
 enum PreviewStates PreviewState;
 static int waitingFrame;
-enum PreviewStates waitMode;
+extern enum PreviewStates waitMode;
 
 #if NeedFunctionPrototypes
 void SetUpPreviewLevel(Display *display, Window window, Colormap colormap)
@@ -139,7 +139,7 @@ static void DoLoadLevel(display, window)
 
     /* Construct the Preview level filename */
     if ((str = getenv("XBOING_LEVELS_DIR")) != NULL)
-        sprintf(levelPath, "%s/level%02d.data", str, lnum);
+        snprintf(levelPath, sizeof(levelPath)-1, "%s/level%02d.data", str, lnum);
     else
         sprintf(levelPath, "%s/level%02d.data", LEVEL_INSTALL_DIR, lnum);
 
