--- VTKPrimitives.cpp.orig	2023-10-22 14:27:22 UTC
+++ VTKPrimitives.cpp
@@ -19,6 +19,8 @@
 #include "vtkRenderer.h"
 #include "vtkActorCollection.h"
 
+#include <iostream>
+
 #include "vtkPolyDataMapper.h"
 #include "vtkDoubleArray.h"
 #include "vtkLODActor.h"
@@ -106,7 +108,7 @@ void VTKPrimitives::AddCube(const double *start, const
 	}
 	if (dim==0)
 	{
-		cerr << "VTKPrimitives::AddCube: Warning, can't draw a Point Box... skipping" << endl;
+		std::cerr << "VTKPrimitives::AddCube: Warning, can't draw a Point Box... skipping" << std::endl;
 		return;
 	}
 	if (dim==1)
@@ -510,7 +512,7 @@ void VTKPrimitives::AddSphericalShell(const double *dC
 	Source_o->Delete();
 	Source_i->Delete();
 #else
-	cerr << "VTKPrimitives::AddSphericalShell: Error, spherical shell not supported by this vkt version, you require vtk 5.10 or higher." << endl;
+	std::cerr << "VTKPrimitives::AddSphericalShell: Error, spherical shell not supported by this vkt version, you require vtk 5.10 or higher." << std::endl;
 #endif
 }
 
@@ -848,7 +850,7 @@ void VTKPrimitives::WritePolyData2File(const char* fil
 
 void VTKPrimitives::WritePolyData2File(const char* filename, double scale)
 {
-	cout << "VTKPrimitives::WritePolyData2File: Dump to vtk file: " << filename << " -- Using scale: " << scale << endl;
+	std::cout << "VTKPrimitives::WritePolyData2File: Dump to vtk file: " << filename << " -- Using scale: " << scale << std::endl;
 	vtkXMLPolyDataWriter* writer  = vtkXMLPolyDataWriter::New();
 	writer->SetFileName(filename);
 
@@ -890,7 +892,7 @@ void VTKPrimitives::WritePolyData2STL(const char* file
 
 void VTKPrimitives::WritePolyData2STL(const char* filename, double scale)
 {
-	cout << "VTKPrimitives::WritePolyData2STL: Dump to stl file: " << filename << " -- Using scale: " << scale << endl;
+	std::cout << "VTKPrimitives::WritePolyData2STL: Dump to stl file: " << filename << " -- Using scale: " << scale << std::endl;
 
 	vtkTriangleFilter* filter = vtkTriangleFilter::New();
 
@@ -932,7 +934,7 @@ void VTKPrimitives::WritePolyData2PLY(const char* file
 
 void VTKPrimitives::WritePolyData2PLY(const char* filename, double scale)
 {
-	cout << "VTKPrimitives::WritePolyData2PLY: Dump to ply file: " << filename << " -- Using scale: " << scale << endl;
+	std::cout << "VTKPrimitives::WritePolyData2PLY: Dump to ply file: " << filename << " -- Using scale: " << scale << std::endl;
 
 	vtkTriangleFilter* filter = vtkTriangleFilter::New();
 
