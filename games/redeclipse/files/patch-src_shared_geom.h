--- src/shared/geom.h.orig	2015-03-22 02:34:16.000000000 +0300
+++ src/shared/geom.h	2015-03-24 22:25:25.797675000 +0300
@@ -1135,7 +1135,7 @@
     bvec &max(const bvec &o)   { x = ::max(x, o.x); y = ::max(y, o.y); z = ::max(z, o.z); return *this; }
     bvec &min(int f)        { x = ::min(int(x), f); y = ::min(int(y), f); z = ::min(int(z), f); return *this; }
     bvec &max(int f)        { x = ::max(int(x), f); y = ::max(int(y), f); z = ::max(int(z), f); return *this; }
-    bvec &abs() { x = fabs(x); y = fabs(y); z = fabs(z); return *this; }
+    bvec &abs() { /* always positive */ return *this; }
     bvec &clamp(int l, int h) { x = ::clamp(int(x), l, h); y = ::clamp(int(y), l, h); z = ::clamp(int(z), l, h); return *this; }
 
     vec tovec() const { return vec(x*(2.0f/255.0f)-1.0f, y*(2.0f/255.0f)-1.0f, z*(2.0f/255.0f)-1.0f); }
