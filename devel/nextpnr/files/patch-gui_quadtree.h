--- gui/quadtree.h.orig	2025-02-09 18:01:57 UTC
+++ gui/quadtree.h
@@ -226,7 +226,7 @@ template <typename CoordinateT, typename ElementT> cla
             return *this;
         bound_ = other.bound_;
         max_elems_ = other.max_elems_;
-        children_ = other.max_children_;
+        //children_ = other.max_children_;
         children_ = other.children_;
         splitx_ = other.splitx_;
         splity_ = other.splity_;
