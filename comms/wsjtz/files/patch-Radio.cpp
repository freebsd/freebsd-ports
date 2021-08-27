--- Radio.cpp.orig	2021-02-01 18:08:30 UTC
+++ Radio.cpp
@@ -45,7 +45,7 @@ namespace Radio
     value *= std::pow (10., scale);
     if (ok)
       {
-        if (value < 0. || value > std::numeric_limits<Frequency>::max ())
+        if (value < 0. || value > (float)std::numeric_limits<Frequency>::max ())
           {
             value = 0.;
             *ok = false;
@@ -70,7 +70,7 @@ namespace Radio
     if (ok)
       {
         if (value < -std::numeric_limits<Frequency>::max ()
-            || value > std::numeric_limits<Frequency>::max ())
+            || value > (float)std::numeric_limits<Frequency>::max ())
           {
             value = 0.;
             *ok = false;
