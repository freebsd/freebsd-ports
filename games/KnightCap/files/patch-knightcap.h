--- knightcap.h	Mon Jan 24 22:20:22 2005
+++ knightcap.h	Mon Jan 24 22:17:19 2005
@@ -632,16 +632,6 @@
 	return i1 > i2? i1 : i2;
 }
 
-static inline float fmin(float i1, float i2)
-{
-	return i1 > i2? i2 : i1;
-}
-
-static inline float fmax(float i1, float i2)
-{
-	return i1 > i2? i1 : i2;
-}
-
 static inline etype emin(etype i1, etype i2)
 {
 	return i1 > i2? i2 : i1;
