--- xpdf/GlobalParams.cc.orig	2007-02-28 00:05:52.000000000 +0200
+++ xpdf/GlobalParams.cc	2008-04-04 15:44:24.000000000 +0300
@@ -1566,6 +1566,10 @@
     *code = xpdfKeyCodeUp;
   } else if (!strcmp(p0, "down")) {
     *code = xpdfKeyCodeDown;
+  } else if (!strcmp(p0, "numpad-plus")) {
+    *code = xpdfKeyPlus;
+  } else if (!strcmp(p0, "numpad-minus")) {
+    *code = xpdfKeyMinus;
   } else if (p0[0] == 'f' && p0[1] >= '1' && p0[1] <= '9' && !p0[2]) {
     *code = xpdfKeyCodeF1 + (p0[1] - '1');
   } else if (p0[0] == 'f' &&
