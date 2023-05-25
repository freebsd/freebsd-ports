--- ImgToolKit.c.orig	1994-11-02 00:30:07.000000000 -0800
+++ ImgToolKit.c	2023-05-25 07:50:21.577290000 -0700
@@ -269,7 +269,7 @@
   curW  = win;
   state = XInternAtom(theDsp, "WM_STATE", True);
   if (state != NULL) {
-    type = NULL;
+    type = 0;
     kidW = win;
     while (kidW != NULL) {
       curW = kidW;
