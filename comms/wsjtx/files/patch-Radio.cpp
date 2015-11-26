--- Radio.cpp.orig	2015-11-25 02:16:24 UTC
+++ Radio.cpp
@@ -38,12 +38,12 @@ namespace Radio
 
   Frequency frequency (QVariant const& v, int scale)
   {
-    return std::llround (v.toDouble () * std::pow (10., scale));
+    return llround (v.toDouble () * std::pow (10., scale));
   }
 
   FrequencyDelta frequency_delta (QVariant const& v, int scale)
   {
-    return std::llround (v.toDouble () * std::pow (10., scale));
+    return llround (v.toDouble () * std::pow (10., scale));
   }
 
 
