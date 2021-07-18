Fixes the redeclaration error. float vs const float.

--- src/modulator.h.orig	2021-07-12 11:03:15 UTC
+++ src/modulator.h
@@ -70,7 +70,7 @@ struct autorotator {
   inline void setdeg (float d) {
     deg = d;
     if (deg < 0.0f) deg = 0.0f;
-    extern float PI_BY_180;
+    extern const float PI_BY_180;
     angle.persec = deg * PI_BY_180;
   }
 
