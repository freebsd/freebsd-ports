--- src/Lib/terragear/tg_misc.cxx.orig	2017-10-07 06:58:20 UTC
+++ src/Lib/terragear/tg_misc.cxx
@@ -112,8 +112,8 @@
     ClipperLib::IntPoint min_pt, max_pt;
     SGGeod min, max;
 
-    min_pt.X = min_pt.Y = LONG_LONG_MAX;
-    max_pt.X = max_pt.Y = LONG_LONG_MIN;
+    min_pt.X = min_pt.Y = LLONG_MAX;
+    max_pt.X = max_pt.Y = LLONG_MIN;
 
     // for each polygon, we need to check the orientation, to set the hole flag...
     for (unsigned int i=0; i<subject.size(); i++)
@@ -377,4 +377,4 @@
         // handle the no intersection case.
         return false;
     }
-}
\ No newline at end of file
+}
