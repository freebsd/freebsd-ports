--- knightcap.h.orig	1998-05-18 01:09:21.000000000 +0200
+++ knightcap.h	2011-06-03 15:40:22.000000000 +0200
@@ -216,6 +216,9 @@
 #define BMAJOR_MASK (BPIECE_MASK & ~BMINOR_MASK)
 #define MAJOR_MASK  (WMAJOR_MASK | BMAJOR_MASK)
 
+#ifdef INFINITY
+#undef INFINITY
+#endif
 #define INFINITY (40.50*STATIC_PAWN_VALUE)
 #define ILLEGAL (-40*STATIC_PAWN_VALUE)
 #define WIN (-(ILLEGAL+1))
@@ -632,16 +635,6 @@
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
