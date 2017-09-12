--- xpdf/XPDFViewer.cc.orig	2008-04-04 15:36:27.000000000 +0300
+++ xpdf/XPDFViewer.cc	2008-04-04 15:41:05.000000000 +0300
@@ -569,6 +569,10 @@
     keyCode = xpdfKeyCodeDown;
   } else if (key >= XK_F1 && key <= XK_F35) {
     keyCode = xpdfKeyCodeF1 + (key - XK_F1);
+  } else if (key == XK_KP_Add) {
+    keyCode = xpdfKeyPlus;
+  } else if (key == XK_KP_Subtract) {
+    keyCode = xpdfKeyMinus;
   } else {
     return;
   }
