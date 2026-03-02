--- QVTKStructure.cpp.orig	2026-03-02 07:18:29 UTC
+++ QVTKStructure.cpp
@@ -17,6 +17,8 @@
 
 #include <QFileDialog>
 
+#include <iostream>
+
 #include "QVTKStructure.h"
 
 #if VTK_MAJOR_VERSION>=9
@@ -280,7 +282,7 @@ void QVTKStructure::RenderGrid()
 		}
 	}
 	else
-		cerr << "QVTKStructure::RenderGrid(): Error, unknown grid type!" << endl;
+		std::cerr << "QVTKStructure::RenderGrid(): Error, unknown grid type!" << std::endl;
 
 	RenderGridDir(0,0);
 	RenderGridDir(1,0);
@@ -325,7 +327,7 @@ void QVTKStructure::RenderGridDir(int dir, unsigned in
 		uiQty[n]=CSGrid->GetQtyLines(n);
 	if ((int)plane_pos>=uiQty[dir])
 	{
-		cerr << "QVTKStructure::RenderGridDir: requested plane postion is out of range, resetting to max value!" << endl;
+		std::cerr << "QVTKStructure::RenderGridDir: requested plane postion is out of range, resetting to max value!" << std::endl;
 		plane_pos = uiQty[dir]-1;
 	}
 
@@ -336,7 +338,7 @@ void QVTKStructure::RenderGridDir(int dir, unsigned in
 			ActorGridPlane[dir]->Delete();
 			gridMapper->Delete();
 			ActorGridPlane[dir]=NULL;
-			cerr << "QVTKStructure::RenderGridDir: Error, rect grid mesh was not created, skipping drawing..." << endl;
+			std::cerr << "QVTKStructure::RenderGridDir: Error, rect grid mesh was not created, skipping drawing..." << std::endl;
 			return;
 		}
 		vtkRectilinearGridGeometryFilter *grid_plane = vtkRectilinearGridGeometryFilter::New();
@@ -372,7 +374,7 @@ void QVTKStructure::RenderGridDir(int dir, unsigned in
 			ActorGridPlane[dir]->Delete();
 			gridMapper->Delete();
 			ActorGridPlane[dir]=NULL;
-			cerr << "QVTKStructure::RenderGridDir: Error, structured grid mesh was not created, skipping drawing..." << endl;
+			std::cerr << "QVTKStructure::RenderGridDir: Error, structured grid mesh was not created, skipping drawing..." << std::endl;
 			return;
 		}
 
@@ -403,7 +405,7 @@ void QVTKStructure::RenderGridDir(int dir, unsigned in
 		}
 	}
 	else
-		cerr << "QVTKStructure::RenderGrid(): Error, unknown grid type!" << endl;
+		std::cerr << "QVTKStructure::RenderGrid(): Error, unknown grid type!" << std::endl;
 
 	gridMapper->SetInputConnection(plane->GetOutputPort());
 	ActorGridPlane[dir]->SetMapper(gridMapper);
