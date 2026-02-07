--- libXg/gwin.c.orig	2023-07-08 20:04:38 UTC
+++ libXg/gwin.c
@@ -455,7 +455,7 @@ Mouseaction(Widget w, XEvent *e, String *p, Cardinal *
 
 static void
 SelCallback(Widget w, XtPointer cldata, Atom *sel, Atom *seltype,
-    XtPointer val, uint64_t *len, int *fmt)
+    XtPointer val, unsigned long *len, int *fmt)
 {
     GwinWidget gw = (GwinWidget)w;
     XTextProperty p = {0};
@@ -486,7 +486,7 @@ SelCallback(Widget w, XtPointer cldata, Atom *sel, Ato
 
 static Boolean
 SendSel(Widget w, Atom *sel, Atom *target, Atom *rtype, XtPointer *ans,
-        uint64_t *anslen, int *ansfmt)
+        unsigned long *anslen, int *ansfmt)
 {
     GwinWidget gw = (GwinWidget)w;
     XTextProperty p = {0};
