$FreeBSD$

diff -u -r1.5 awt_InputMethod.c
--- ../src/solaris/native/sun/awt/awt_InputMethod.c	10 Sep 2001 05:31:35 -0000	1.5
+++ ../src/solaris/native/sun/awt/awt_InputMethod.c	18 Oct 2002 02:58:26 -0000
@@ -1320,17 +1320,56 @@
     X11InputMethodData *pX11IMData =
 	(X11InputMethodData *) (unsigned long) data;
     char *xText;
+    char *ret;
     jstring jText;
 
+    XIMPreeditState preeditState = XIMPreeditUnKnown;
+    XVaNestedList preeditAttr;
+    int bGetState = FALSE;
+
     AWT_LOCK();
 
-    if (pX11IMData->current_ic)
+    if (pX11IMData->current_ic) {
+	preeditAttr = XVaCreateNestedList(0, XNPreeditState, &preeditState, 
+                                          NULL);
+        if (!XGetICValues(pX11IMData->current_ic, XNPreeditAttributes, 
+                          preeditAttr, NULL)) {
+             bGetState = TRUE;
+        }
+        XFree(preeditAttr);
+
 	xText = XmbResetIC(pX11IMData->current_ic);
+
+        if (bGetState) {
+             preeditAttr = XVaCreateNestedList(0, XNPreeditState, 
+                                               preeditState, 0);
+             XSetICValues(pX11IMData->current_ic,
+                          XNPreeditAttributes, preeditAttr, NULL);
+             XFree(preeditAttr);
+        }
+    }
     else {
 	/*
 	 * If there is no reference to the current XIC, try to reset both XICs.
 	 */
+        preeditAttr = XVaCreateNestedList(0, XNPreeditState, &preeditState, 
+                                          NULL);
+        if (!XGetICValues(pX11IMData->ic_active, XNPreeditAttributes, 
+                          preeditAttr, NULL)) {
+            bGetState = TRUE;
+        }
+        XFree(preeditAttr);
+
 	xText = XmbResetIC(pX11IMData->ic_active);
+
+        if (bGetState) {
+            preeditAttr = XVaCreateNestedList(0, XNPreeditState, 
+                                              preeditState, 0);
+            XSetICValues(pX11IMData->ic_active, XNPreeditAttributes, 
+                         preeditAttr, NULL);
+            XFree(preeditAttr);
+        }
+
         /*it may also means that the real client component does 
           not have focus -- has been deactivated... its xic should 
           not have the focus, bug#4284651 showes reset XIC for htt 
