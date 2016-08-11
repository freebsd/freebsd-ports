--- intern/itasc/kdl/tree.hpp.orig	2016-07-25 09:36:50 UTC
+++ intern/itasc/kdl/tree.hpp
@@ -34,7 +34,7 @@
     //Forward declaration
     class TreeElement;
     // Eigen allocator is needed for alignment of Eigen data types
-    typedef std::map<std::string,TreeElement, std::less<std::string>, Eigen::aligned_allocator<std::pair<std::string, TreeElement> > > SegmentMap;
+    typedef std::map<std::string,TreeElement, std::less<std::string>, Eigen::aligned_allocator<std::pair<const std::string, TreeElement> > > SegmentMap;
 
     class TreeElement
     {
