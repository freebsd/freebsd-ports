--- ./src/Model/CModel.cpp.orig	Mon Jul 21 18:40:40 2003
+++ ./src/Model/CModel.cpp	Mon Jul 21 18:41:05 2003
@@ -68,17 +68,17 @@
 }
 
 
-BBox CModel::getBBox(bool selectedOnly = true) const
+BBox CModel::getBBox(bool selectedOnly) const
 {
 	return BBox();
 }
 
-BBox CModel::getBBox(const Matrix4& m, bool selectedOnly = true) const
+BBox CModel::getBBox(const Matrix4& m, bool selectedOnly) const
 {
 	return BBox();
 }
 
-BBox CModel::getBBox(const Transformation *x, bool selectedOnly = true) const
+BBox CModel::getBBox(const Transformation *x, bool selectedOnly) const
 {
 	return BBox();
 }
