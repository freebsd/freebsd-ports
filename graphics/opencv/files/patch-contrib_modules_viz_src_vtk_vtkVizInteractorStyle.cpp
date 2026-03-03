--- contrib/modules/viz/src/vtk/vtkVizInteractorStyle.cpp.orig	2026-03-03 08:26:40 UTC
+++ contrib/modules/viz/src/vtk/vtkVizInteractorStyle.cpp
@@ -45,6 +45,8 @@
 
 #include "../precomp.hpp"
 
+#include <iostream>
+
 namespace cv { namespace viz
 {
     vtkStandardNewMacro(vtkVizInteractorStyle)
@@ -96,7 +98,7 @@ void cv::viz::vtkVizInteractorStyle::saveScreenshot(co
     snapshot_writer->SetFileName(file.c_str());
     snapshot_writer->Write();
 
-    cout << "Screenshot successfully captured (" << file.c_str() << ")" << endl;
+    std::cout << "Screenshot successfully captured (" << file.c_str() << ")" << std::endl;
 }
 
 //////////////////////////////////////////////////////////////////////////////////////////////
@@ -118,7 +120,7 @@ void cv::viz::vtkVizInteractorStyle::exportScene(const
     exporter->SetInput(Interactor->GetRenderWindow());
     exporter->Write();
 
-    cout << "Scene successfully exported (" << file.c_str() << ")" << endl;
+    std::cout << "Scene successfully exported (" << file.c_str() << ")" << std::endl;
 }
 
 void cv::viz::vtkVizInteractorStyle::exportScene()
