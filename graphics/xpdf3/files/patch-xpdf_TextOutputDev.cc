--- xpdf/TextOutputDev.cc.orig	2019-10-04 19:39:06 UTC
+++ xpdf/TextOutputDev.cc
@@ -2472,6 +2472,12 @@ TextBlock *TextPage::split(GList *charsA, int rot) {
 
   //----- compute the horizontal and vertical profiles
 
+  if (xMin / splitPrecision < 0.5 * INT_MIN ||
+      xMax / splitPrecision > 0.5 * INT_MAX ||
+      yMin / splitPrecision < 0.5 * INT_MIN ||
+      xMax / splitPrecision > 0.5 * INT_MAX) {
+    return NULL;
+  }
   // add some slack to the array bounds to avoid floating point
   // precision problems
   xMinI = (int)floor(xMin / splitPrecision) - 1;
