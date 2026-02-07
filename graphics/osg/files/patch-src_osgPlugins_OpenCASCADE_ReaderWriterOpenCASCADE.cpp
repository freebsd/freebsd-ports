--- src/osgPlugins/OpenCASCADE/ReaderWriterOpenCASCADE.cpp.orig	2022-12-01 18:17:31 UTC
+++ src/osgPlugins/OpenCASCADE/ReaderWriterOpenCASCADE.cpp
@@ -211,7 +211,7 @@ osg::ref_ptr<osg::Geometry> ReaderWritterOpenCASCADE::
                 {
                     // populate vertex list
                     // Ref: http://www.opencascade.org/org/forum/thread_16694/?forum=3
-                    gp_Pnt pt = (triangulation->Nodes())(j).Transformed(transformation * location.Transformation());
+                    gp_Pnt pt = (triangulation->Node(j)).Transformed(transformation * location.Transformation());
                     vertexList->push_back(osg::Vec3(pt.X(), pt.Y(), pt.Z()));
 
                     // populate color list
