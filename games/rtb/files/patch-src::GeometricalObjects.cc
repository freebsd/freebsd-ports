--- src/GeometricalObjects.cc.orig	Tue Sep 21 18:01:56 2004
+++ src/GeometricalObjects.cc	Tue Sep 21 18:02:43 2004
@@ -89,7 +89,7 @@
   if( s < 0 || s > length ) return infinity;
   if( t < 0 && ((d=-dot(y, direction)) < 0.0 || d > length ) ) return infinity;
 
-  return max(t, 0);
+  return Max(t, 0);
 }
 
 Vector2D
@@ -169,7 +169,7 @@
   double r = size+radius;
   double c = dt*dt + speedsqr * (r*r - lengthsqr(y));
   if( c < 0.0 || dt <= 0.0) return infinity;
-  return max( (dt - sqrt(c))/speedsqr, 0);
+  return Max( (dt - sqrt(c))/speedsqr, 0);
 }
 
 bool
@@ -231,7 +231,7 @@
   if( speedsqr == 0.0 ) return infinity;
   double dt = dot(vel, y);
   double c = dt*dt + speedsqr*((size-radius)*(size-radius) - lengthsqr(y));
-  return max( (dt + sqrt(c))/speedsqr, 0 );
+  return Max( (dt + sqrt(c))/speedsqr, 0 );
 }
 
 bool
@@ -318,7 +318,7 @@
       r = size + outer_radius;
       c = dt*dt + speedsqr * (r*r - lengthsqr(d));
       if( c < 0.0 || dt <= 0.0) return infinity;
-      t = max( (dt - sqrt(c))/speedsqr, 0);
+      t = Max( (dt - sqrt(c))/speedsqr, 0);
 
       if( within_angle( vec2angle( vel * t - d ) ) )
         return t;
@@ -336,7 +336,7 @@
   c = dt*dt + speedsqr*( r*r - lengthsqr(d) );
   if( c < 0.0 ) return infinity;  // Can happen if object outside circle
   
-  t =  max( (dt + sqrt(c))/speedsqr, 0 );
+  t =  Max( (dt + sqrt(c))/speedsqr, 0 );
   
   if( !within_angle( vec2angle( vel * t - d  ) ) )
     return infinity;
