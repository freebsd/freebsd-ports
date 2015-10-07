--- src/detail/GeometrySet.cpp.orig	2015-01-14 13:59:05 UTC
+++ src/detail/GeometrySet.cpp
@@ -557,10 +557,10 @@ void recompose_points( const typename Ge
 
 // compare less than
 struct ComparePoints {
-    bool operator()( const CGAL::Point_2<Kernel>& lhs, const CGAL::Point_2<Kernel>& rhs ) {
+    bool operator()( const CGAL::Point_2<Kernel>& lhs, const CGAL::Point_2<Kernel>& rhs ) const {
         return lhs.x() < rhs.x() || lhs.y() < rhs.y();
     }
-    bool operator()( const CGAL::Point_3<Kernel>& lhs, const CGAL::Point_3<Kernel>& rhs ) {
+    bool operator()( const CGAL::Point_3<Kernel>& lhs, const CGAL::Point_3<Kernel>& rhs ) const {
         return lhs.x() < rhs.x() || lhs.y() < rhs.y() || lhs.z() < rhs.z();
     }
 };
