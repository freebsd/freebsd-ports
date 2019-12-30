--- scrollbar.c.orig	2016-11-04 21:41:21 UTC
+++ scrollbar.c
@@ -49,6 +49,7 @@ extern int BackgroundPixmapIsOn;
 static void ScrollTextTo();
 static void ScrollTextUpDownBy();
 
+extern Boolean SendMousePosition();
 
 /* resize the text window for a terminal screen, modifying the
  * appropriate WM_SIZE_HINTS and taking advantage of bit gravity.
@@ -555,6 +556,7 @@ void HandleScrollForward (gw, event, params, nparams)
     XtermWidget w = (XtermWidget) gw;
     register TScreen *screen = &w->screen;
 
+    if (SendMousePosition(gw, event)) return;
     ScrollTextUpDownBy (gw, (XtPointer) NULL,
 			(XtPointer)params_to_pixels (screen, params, (int) *nparams));
     return;
@@ -571,6 +573,7 @@ void HandleScrollBack (gw, event, params, nparams)
     XtermWidget w = (XtermWidget) gw;
     register TScreen *screen = &w->screen;
 
+    if (SendMousePosition(gw, event)) return;
     ScrollTextUpDownBy (gw, (XtPointer) NULL,
 			(XtPointer)-params_to_pixels (screen, params, (int) *nparams));
     return;
