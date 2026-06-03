Update for VTK 9 compatibility.

- Remove deprecated vtkToolkits.h header (no longer exists in VTK 9)
- Convert vtkStdString to const char* when calling SetCaption()
  (VTK 9 changed API to require explicit conversion)

--- vv/vvSlicer.cxx.orig	2025-04-17 12:54:38 UTC
+++ vv/vvSlicer.cxx
@@ -44,7 +44,6 @@
 #include <vtkImageData.h>
 #include <vtkImageActor.h>
 #include <vvBlendImageActor.h>
-#include <vtkToolkits.h>
 #include <vtkObjectFactory.h>
 #include <vtkPointData.h>
 #include <vtkDataArray.h>
@@ -1877,7 +1876,7 @@ void vvSlicer::DisplayLandmarks()
 	  double *position = mLandClipper->GetOutput()->GetPoint(id);
       vtkStdString label = static_cast<vtkStringArray*>(mLandClipper->GetOutput()->GetPointData()->GetAbstractArray("labels"))->GetValue(id);
       vtkSmartPointer<vtkCaptionActor2D> label_actor = vtkSmartPointer<vtkCaptionActor2D>::New();
-      label_actor->SetCaption(label);
+      label_actor->SetCaption(label.c_str());
       label_actor->SetAttachmentPoint(position);
       label_actor->GetCaptionTextProperty()->SetColor(1,0,0);
       label_actor->GetCaptionTextProperty()->SetOrientation(33.333333);
