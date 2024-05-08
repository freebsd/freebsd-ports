--- Radio.cpp.orig	2021-12-28 16:31:58 UTC
+++ Radio.cpp
@@ -54,7 +54,7 @@ namespace Radio
     value *= std::pow (10., scale);
     if (ok)
       {
-        if (value < 0. || value > std::numeric_limits<Frequency>::max ())
+        if (value < 0. || value > (float)std::numeric_limits<Frequency>::max ())
           {
             value = 0.;
             *ok = false;
@@ -92,7 +92,7 @@ namespace Radio
     if (ok)
       {
         if (value < -std::numeric_limits<Frequency>::max ()
-            || value > std::numeric_limits<Frequency>::max ())
+            || value > (float)std::numeric_limits<Frequency>::max ())
           {
             value = 0.;
             *ok = false;
