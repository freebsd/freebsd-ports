--- scrollbar.c.orig	Thu Feb 13 02:06:51 2003
+++ scrollbar.c	Thu Feb 13 02:07:58 2003
@@ -46,6 +46,7 @@
 static void ScrollTextTo();
 static void ScrollTextUpDownBy();
 
+extern Boolean SendMousePosition();
 
 /* resize the text window for a terminal screen, modifying the
  * appropriate WM_SIZE_HINTS and taking advantage of bit gravity.
@@ -535,6 +536,7 @@
     XtermWidget w = (XtermWidget) gw;
     register TScreen *screen = &w->screen;
 
+    if (SendMousePosition(gw, event)) return;
     ScrollTextUpDownBy (gw, (XtPointer) NULL,
 			(XtPointer)params_to_pixels (screen, params, (int) *nparams));
     return;
@@ -551,6 +553,7 @@
     XtermWidget w = (XtermWidget) gw;
     register TScreen *screen = &w->screen;
 
+    if (SendMousePosition(gw, event)) return;
     ScrollTextUpDownBy (gw, (XtPointer) NULL,
 			(XtPointer)-params_to_pixels (screen, params, (int) *nparams));
     return;

