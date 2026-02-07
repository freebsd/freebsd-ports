--- util/misc.c.orig	2017-02-04 16:15:41 UTC
+++ util/misc.c
@@ -400,7 +400,10 @@ Boolean FindBestVisual(Display *display, const char *a
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
