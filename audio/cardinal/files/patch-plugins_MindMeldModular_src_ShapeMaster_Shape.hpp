-- fix C++ compilation failure

--- plugins/MindMeldModular/src/ShapeMaster/Shape.hpp.orig	2026-09-14 19:57:15 UTC
+++ plugins/MindMeldModular/src/ShapeMaster/Shape.hpp
@@ -157,7 +157,7 @@ class Shape {	
 	T calcY(int p, T _x) {
 		// _x is relative to points[p].x
 		// do not call on last point
-		T dx = std::abs<T>((T)points[p + 1].x - (T)points[p].x);
+		T dx = std::abs((T)points[p + 1].x - (T)points[p].x);
 		T dy = (T)points[p + 1].y - (T)points[p].y;
 		T eval = (T)points[p].y;
 		if (type[p] == 0) {
