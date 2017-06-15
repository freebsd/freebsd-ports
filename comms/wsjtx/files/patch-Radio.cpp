--- Radio.cpp.orig	2017-01-05 15:57:45 UTC
+++ Radio.cpp
@@ -30,7 +30,7 @@ namespace Radio
       {
         value = v.toDouble ();
       }
-    return std::llround (value * std::pow (10., scale));
+    return llround (value * std::pow (10., scale));
   }
 
   FrequencyDelta frequency_delta (QVariant const& v, int scale, QLocale const& locale)
@@ -44,7 +44,7 @@ namespace Radio
       {
         value = v.toDouble ();
       }
-    return std::llround (value * std::pow (10., scale));
+    return llround (value * std::pow (10., scale));
   }
 
 
