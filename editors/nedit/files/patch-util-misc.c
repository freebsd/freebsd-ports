--- util/misc.c.orig	2004-08-09 18:20:00.000000000 -0400
+++ util/misc.c	2012-02-03 02:54:30.000000000 -0500
@@ -383,7 +383,10 @@
 	*colormap = cachedColormap;
 	return (*visual == DefaultVisual(display, screen));
     }
-    
+
+    /* Set "Default" visual to avoid crashes with the detected best ones. */
+    reqID = DefaultVisual(display, screen)->visualid;
+
     /* Read the visualID and installColormap resources for the application.
        visualID can be specified either as a number (the visual id as
        shown by xdpyinfo), as a visual class name, or as Best or Default. */
