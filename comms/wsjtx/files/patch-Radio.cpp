--- Radio.cpp.orig	2015-12-11 00:00:13 UTC
+++ Radio.cpp
@@ -33,7 +33,7 @@ namespace Radio
       {
         value = v.toDouble ();
       }
-    return std::llround (value * std::pow (10., scale));
+    return llround (value * std::pow (10., scale));
   }
 
   FrequencyDelta frequency_delta (QVariant const& v, int scale, QLocale const& locale)
@@ -47,7 +47,7 @@ namespace Radio
       {
         value = v.toDouble ();
       }
-    return std::llround (value * std::pow (10., scale));
+    return llround (value * std::pow (10., scale));
   }
 
 
