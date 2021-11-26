--- src/Bif_F12_FORMAT.cc.orig	2019-06-23 12:39:20 UTC
+++ src/Bif_F12_FORMAT.cc
@@ -576,18 +576,17 @@ right_decorator:   /// the right decorator
 
 fields_done:
 
-int sum = 0;
-   sum += left_deco.out_len = left_deco .format.size();
+   left_deco.out_len = left_deco.format.size();
 
-   sum += int_part  .out_len = int_part  .format.size();
+   int_part.out_len = int_part.format.size();
 
    if (fract_part.format.size())
-      sum += fract_part.out_len = fract_part.format.size() + 1;
+      fract_part.out_len = fract_part.format.size() + 1;
 
    if (exponent.size())
       {
-        sum += expo_deco.out_len = expo_deco.size();
-        sum += exponent.out_len = exponent.format.size() + 1;
+        expo_deco.out_len = expo_deco.size();
+        exponent.out_len = exponent.format.size() + 1;
       }
 
    right_deco.out_len = right_deco.format.size();
