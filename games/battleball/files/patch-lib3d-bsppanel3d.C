--- lib3d/bsppanel3d.C.orig	2011-01-20 12:02:35.000000000 +0100
+++ lib3d/bsppanel3d.C	2011-01-20 12:03:32.000000000 +0100
@@ -42,7 +42,7 @@
   }
 
   pt3d2Vec3f(normal,poly.plane_normal);
-  poly.material_index= (int) this;
+  poly.material_index= (intptr_t) this;
   return poly;
 }
 
