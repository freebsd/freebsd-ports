--- src/dirnode.cpp.orig	2014-10-16 02:23:22 UTC
+++ src/dirnode.cpp
@@ -582,7 +582,7 @@ void RDirNode::calcRadius() {
     //this->dir_radius_sqrt = sqrt(dir_radius); //dir_radius_sqrt is not used
 
 //    this->parent_radius = std::max(1.0, parent_circ / PI);
-    this->parent_radius = std::max(1.0, sqrt(total_file_area) * gGourceDirPadding);
+    this->parent_radius = std::max(1.0f, (float)sqrt(total_file_area) * gGourceDirPadding);
 }
 
 float RDirNode::distanceToParent() const{
