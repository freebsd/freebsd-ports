--- src/lincity/MapPoint.hpp.orig	2025-09-27 07:10:50 UTC
+++ src/lincity/MapPoint.hpp
@@ -25,8 +25,6 @@
 #include <cstddef>      // for size_t
 #include <ostream>      // for ostream
 
-namespace std { template<class Key> struct hash; }  // IWYU pragma: keep
-
 class MapPoint {
 public:
   MapPoint(int x = 0, int y = 0);
