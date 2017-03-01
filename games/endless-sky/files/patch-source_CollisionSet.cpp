--- source/CollisionSet.cpp.orig	2017-01-18 02:04:49 UTC
+++ source/CollisionSet.cpp
@@ -22,6 +22,7 @@ PARTICULAR PURPOSE.  See the GNU General
 #include <algorithm>
 #include <numeric>
 #include <set>
+#include <cstdlib>
 
 using namespace std;
 
@@ -179,8 +180,8 @@ Body *CollisionSet::Line(const Projectil
 	int stepX = (x <= endX ? 1 : -1);
 	int stepY = (y <= endY ? 1 : -1);
 	// Calculate the slope of the line, shifted so it is positive in both axes.
-	int mx = abs(endX - x);
-	int my = abs(endY - y);
+	int mx = std::abs(endX - x);
+	int my = std::abs(endY - y);
 	// Behave as if each grid cell has this width and height. This guarantees
 	// that we only need to work with integer coordinates.
 	int scale = max(mx, 1) * max(my, 1);
