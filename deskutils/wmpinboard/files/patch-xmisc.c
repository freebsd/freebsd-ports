--- src/xmisc.c.orig	2009-05-27 17:03:25.000000000 +0400
+++ src/xmisc.c	2009-05-27 16:42:40.000000000 +0400
@@ -204,7 +204,7 @@
     return;
   }
 
-  if (XGetIMValues(xim, XNQueryInputStyle, &xim_styles, 0) || !xim_styles) {
+  if (XGetIMValues(xim, XNQueryInputStyle, &xim_styles, NULL) || !xim_styles) {
     XCloseIM(xim);
 #ifdef DEBUG_IC
     fprintf(stderr, "Input method doesn't support any style.\n");
@@ -258,7 +258,7 @@
   }
 
   InputContext = XCreateIC(xim, XNInputStyle, input_style,
-    XNClientWindow, win, XNFocusWindow, win, 0);
+    XNClientWindow, win, XNFocusWindow, win, NULL);
 
   if (!InputContext) {
     XCloseIM(xim);


