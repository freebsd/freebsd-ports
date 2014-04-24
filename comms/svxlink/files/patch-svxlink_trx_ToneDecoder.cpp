--- svxlink/trx/ToneDetector.cpp.orig	2014-04-09 23:45:04.000000000 -0700
+++ svxlink/trx/ToneDetector.cpp	2014-04-09 23:47:33.000000000 -0700
@@ -335,7 +335,7 @@
 {
   if (thresh > 0.0f)
   {
-    det_par->peak_thresh = exp10f(thresh/10.0f);
+    det_par->peak_thresh = powf(10, thresh/10.0f);
   }
   else
   {
@@ -348,7 +348,7 @@
 {
   if (thresh > 0.0f)
   {
-    undet_par->peak_thresh = exp10f(thresh/10.0f);
+    undet_par->peak_thresh = powf(10, thresh/10.0f);
   }
   else
   {
