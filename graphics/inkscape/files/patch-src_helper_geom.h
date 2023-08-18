--- src/helper/geom.h.orig	2023-08-24 15:45:30 UTC
+++ src/helper/geom.h
@@ -55,7 +55,7 @@ inline Geom::Coord triangle_area(Geom::Point const &p1
     return p1[X] * p2[Y] + p1[Y] * p3[X] + p2[X] * p3[Y] - p2[Y] * p3[X] - p1[Y] * p2[X] - p1[X] * p3[Y];
 }
 
-inline auto rounddown(Geom::IntPoint const &a, Geom::IntPoint const &b)
+inline auto round_down(Geom::IntPoint const &a, Geom::IntPoint const &b)
 {
     using namespace Inkscape::Util;
     return Geom::IntPoint(round_down(a.x(), b.x()), round_down(a.y(), b.y()));
