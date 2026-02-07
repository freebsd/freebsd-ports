--- utils/Point.hpp.orig	2018-08-19 20:15:17 UTC
+++ utils/Point.hpp
@@ -22,15 +22,6 @@ inline bool feq( const float &f1, const float &f2)
     return fabs(f1-f2) < EPSILON;
 }
 
-inline float fmin( const float &f1, const float &f2 )
-{
-    return f1 < f2 ? f1 : f2;
-}
-
-inline float fmax( const float &f1, const float &f2 )
-{
-    return f1 > f2 ? f1 : f2;
-}
 //-----------------------------------------------------------------------
 
 struct Point2D
