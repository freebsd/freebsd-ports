--- intro.c.orig	1996-11-22 01:28:46 UTC
+++ intro.c
@@ -120,7 +120,7 @@ enum IntroStates IntroState;
 Pixmap bigtitlePixmap, bigtitlePixmapM;
 Pixmap stars[12], starsM[12];
 static int waitingFrame;
-enum IntroStates waitMode;
+extern enum IntroStates waitMode;
 
 #if NeedFunctionPrototypes
 void SetUpIntroduction(Display *display, Window window, Colormap colormap)
