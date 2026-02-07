--- hlrad/mathutil.cpp.orig	2016-03-30 06:24:01 UTC
+++ hlrad/mathutil.cpp
@@ -20,7 +20,7 @@ inline bool PointInEdge(const vec_t* con
 // PointInWall - check a lerpWall_t boundary
 //===============================================
 
-inline bool PointInWall(const lerpWall_t* const wall, const vec_t* const point)
+bool PointInWall(const lerpWall_t* const wall, const vec_t* const point)
 {
 	for(int counter = 0; counter < NUM_LERP_POINTS; counter++)
 	{
@@ -49,7 +49,7 @@ inline bool PointInWinding(const Winding
 // PointInTri - check a boundary defined by 3 points
 //==================================================
 
-inline bool PointInTri(const vec_t* const point, const dplane_t* const plane, const vec_t* const p1, const vec_t* const p2, const vec_t* const p3)
+bool PointInTri(const vec_t* const point, const dplane_t* const plane, const vec_t* const p1, const vec_t* const p2, const vec_t* const p3)
 {
 	return (PointInEdge(point,p1,p2,plane->normal) && PointInEdge(point,p2,p3,plane->normal) && PointInEdge(point,p3,p1,plane->normal));
 }
@@ -131,7 +131,7 @@ inline bool LineSegmentIntersectsFace(co
 // point in point parameter if it exists
 //==================================================
 
-inline bool LineSegmentIntersectsPlane(const dplane_t& plane, const vec_t* const p1, const vec_t* const p2, vec3_t& point)
+bool LineSegmentIntersectsPlane(const dplane_t& plane, const vec_t* const p1, const vec_t* const p2, vec3_t& point)
 {
 	vec3_t line;
 	VectorSubtract(p2,p1,line);
@@ -156,7 +156,7 @@ inline bool LineSegmentIntersectsPlane(c
 // PlaneFromPoints
 //==================================================
 
-inline void PlaneFromPoints(const vec_t* const p1, const vec_t* const p2, const vec_t* const p3, dplane_t* plane)
+void PlaneFromPoints(const vec_t* const p1, const vec_t* const p2, const vec_t* const p3, dplane_t* plane)
 {
 	vec3_t	temp, temp2;
 	VectorSubtract(p3,p2,temp);
@@ -170,7 +170,7 @@ inline void PlaneFromPoints(const vec_t*
 // SnapToPlane
 //==================================================
 
-inline void SnapToPlane(const dplane_t* const plane, vec_t* const point, const vec_t offset)
+void SnapToPlane(const dplane_t* const plane, vec_t* const point, const vec_t offset)
 {
 	vec_t scale = (plane->dist + offset);
 	scale -= DotProduct(plane->normal,point);
@@ -243,4 +243,4 @@ int TestSegmentAgainstOpaqueList(const v
 	}
 #endif
     return -1; //not completely blocked
-}
\ No newline at end of file
+}
