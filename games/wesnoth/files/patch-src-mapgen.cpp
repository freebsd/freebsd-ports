--- src/mapgen.cpp.orig	Thu Apr  8 06:25:14 2004
+++ src/mapgen.cpp	Fri Apr  9 10:28:48 2004
@@ -127,8 +127,8 @@
 
 		//we have to check whether this is actually a valley
 		if(island_size != 0) {
-			const size_t diffx = abs(x1 - center_x);
-			const size_t diffy = abs(y1 - center_y);
+			const size_t diffx = abs((int)(x1 - center_x));
+			const size_t diffy = abs((int)(y1 - center_y));
 			const size_t dist = size_t(sqrt(double(diffx*diffx + diffy*diffy)));
 			is_valley = dist > island_size;
 		}
