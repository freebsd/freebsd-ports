Fix the build with clang and libc++.

Fixed upstream in https://sourceforge.net/p/brlcad/patches/243/
Index: src/librt/primitives/brep/brep.cpp
===================================================================
--- src/librt/primitives/brep/brep.cpp	(revision 58323)
+++ src/librt/primitives/brep/brep.cpp	(working copy)
@@ -537,12 +537,12 @@
 	return *this;
     }
 
-    bool operator==(const brep_hit& h)
+    bool operator==(const brep_hit& h) const
     {
 	return NEAR_ZERO(dist - h.dist, BREP_SAME_POINT_TOLERANCE);
     }
 
-    bool operator<(const brep_hit& h)
+    bool operator<(const brep_hit& h) const
     {
 	return dist < h.dist;
     }
