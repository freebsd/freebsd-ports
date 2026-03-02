--- vtkInteractorStyleRubberBand2DPlane.cpp.orig	2026-03-02 05:23:42 UTC
+++ vtkInteractorStyleRubberBand2DPlane.cpp
@@ -24,6 +24,9 @@
 #include "vtkRenderWindow.h"
 #include "vtkRenderWindowInteractor.h"
 
+#include <iostream>
+
+
 vtkStandardNewMacro(vtkInteractorStyleRubberBand2DPlane);
 
 vtkInteractorStyleRubberBand2DPlane::vtkInteractorStyleRubberBand2DPlane() : vtkInteractorStyleRubberBand2D()
@@ -56,7 +59,7 @@ void vtkInteractorStyleRubberBand2DPlane::OnMouseMove(
 				n_dir = n;
 		if (n_dir<0)
 		{
-			cerr << __func__ << ": Error, no view in x-, y- or z-direction, skipping panning!";
+			std::cerr << __func__ << ": Error, no view in x-, y- or z-direction, skipping panning!";
 			return;
 		}
 
