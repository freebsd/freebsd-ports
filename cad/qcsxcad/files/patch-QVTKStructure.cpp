- workaround for https://github.com/thliebig/QCSXCAD/issues/10

--- QVTKStructure.cpp.orig	2022-10-23 18:25:43 UTC
+++ QVTKStructure.cpp
@@ -113,12 +113,12 @@ QVTKStructure::QVTKStructure()
 #endif
 
 	ren = vtkRenderer::New();
-	VTKWidget->GetRenderWindow()->AddRenderer(ren);
+	VTKWidget->renderWindow()->AddRenderer(ren);
 
 	AddAxes();
 	SetBackgroundColor(255,255,255);
 
-	SetCallback(VTKWidget->GetRenderWindow()->GetInteractor());
+	SetCallback(VTKWidget->renderWindow()->GetInteractor());
 }
 
 QVTKStructure::~QVTKStructure()
@@ -137,7 +137,7 @@ void QVTKStructure::AddAxes()
 	marker->SetOrientationMarker(assembly);
 	marker->SetViewport(0.0,0.0,0.25,0.25);
 
-	marker->SetInteractor(VTKWidget->GetRenderWindow()->GetInteractor());
+	marker->SetInteractor(VTKWidget->renderWindow()->GetInteractor());
 	marker->SetEnabled(1);
 	marker->InteractiveOff();
 
@@ -159,7 +159,7 @@ void QVTKStructure::SetBackgroundColor(int r, int g, i
 	{
 		if (ActorGridPlane[i]!=NULL) ActorGridPlane[i]->GetProperty()->SetColor(irgb);
 	}
-    VTKWidget->GetRenderWindow()->GetInteractor()->Render();
+    VTKWidget->renderWindow()->GetInteractor()->Render();
 }
 
 void QVTKStructure::SetGeometry(ContinuousStructure *CS)
@@ -277,20 +277,20 @@ void QVTKStructure::RenderGrid()
 void QVTKStructure::RenderGridX(int plane_pos)
 {
 	RenderGridDir(0,plane_pos);
-	VTKWidget->GetRenderWindow()->GetInteractor()->Render();
+	VTKWidget->renderWindow()->GetInteractor()->Render();
 }
 
 void QVTKStructure::RenderGridY(int plane_pos)
 {
 	RenderGridDir(1,plane_pos);
-	VTKWidget->GetRenderWindow()->GetInteractor()->Render();
+	VTKWidget->renderWindow()->GetInteractor()->Render();
 
 }
 
 void QVTKStructure::RenderGridZ(int plane_pos)
 {
 	RenderGridDir(2,plane_pos);
-	VTKWidget->GetRenderWindow()->GetInteractor()->Render();
+	VTKWidget->renderWindow()->GetInteractor()->Render();
 }
 
 void QVTKStructure::RenderGridDir(int dir, unsigned int plane_pos)
@@ -413,13 +413,13 @@ void QVTKStructure::SetGridOpacity(int val)
 	{
 		if (ActorGridPlane[i]!=NULL) ActorGridPlane[i]->GetProperty()->SetOpacity((double)val/255.0);
 	}
-	VTKWidget->GetRenderWindow()->GetInteractor()->Render();
+	VTKWidget->renderWindow()->GetInteractor()->Render();
 }
 
 void QVTKStructure::ResetView()
 {
 	ren->ResetCamera();
-    VTKWidget->GetRenderWindow()->GetInteractor()->Render();
+    VTKWidget->renderWindow()->GetInteractor()->Render();
 }
 
 void QVTKStructure::setXY()
@@ -472,7 +472,7 @@ void QVTKStructure::SetPropOpacity(unsigned int uiID, 
 			if (LayerPrimitives.at(i).VTKProp!=NULL) LayerPrimitives.at(i).VTKProp->SetOpacity2All((double)val/255.0);
 		}
 	}
-	VTKWidget->GetRenderWindow()->GetInteractor()->Render();
+	VTKWidget->renderWindow()->GetInteractor()->Render();
 }
 
 void QVTKStructure::RenderGeometry()
@@ -679,7 +679,7 @@ void QVTKStructure::RenderGeometry()
 			}
 		}
 	}
-	VTKWidget->GetRenderWindow()->GetInteractor()->Render();
+	VTKWidget->renderWindow()->GetInteractor()->Render();
 }
 
 void QVTKStructure::RenderDiscMaterialModel()
@@ -716,7 +716,7 @@ void QVTKStructure::RenderDiscMaterialModel()
 			delete transform;
 		}
 	}
-	VTKWidget->GetRenderWindow()->GetInteractor()->Render();
+	VTKWidget->renderWindow()->GetInteractor()->Render();
 }
 
 void QVTKStructure::SetParallelProjection(bool val, bool render)
@@ -725,18 +725,18 @@ void QVTKStructure::SetParallelProjection(bool val, bo
 	cam->SetParallelProjection(val);
 
 	if (render)
-		VTKWidget->GetRenderWindow()->GetInteractor()->Render();
+		VTKWidget->renderWindow()->GetInteractor()->Render();
 }
 
 void QVTKStructure::Set2DInteractionStyle(bool val, bool render)
 {
 	if (val)
-		VTKWidget->GetRenderWindow()->GetInteractor()->SetInteractorStyle(vtkInteractorStyleRubberBand2DPlane::New());
+		VTKWidget->renderWindow()->GetInteractor()->SetInteractorStyle(vtkInteractorStyleRubberBand2DPlane::New());
 	else
-		VTKWidget->GetRenderWindow()->GetInteractor()->SetInteractorStyle(vtkInteractorStyleTrackballCamera::New());
+		VTKWidget->renderWindow()->GetInteractor()->SetInteractorStyle(vtkInteractorStyleTrackballCamera::New());
 
 	if (render)
-		VTKWidget->GetRenderWindow()->GetInteractor()->Render();
+		VTKWidget->renderWindow()->GetInteractor()->Render();
 }
 
 void QVTKStructure::SaveCamData()
@@ -765,7 +765,7 @@ void QVTKStructure::RestoreCamData(bool render)
 	Camera->Modified();
 
 	if (render)
-		VTKWidget->GetRenderWindow()->GetInteractor()->Render();
+		VTKWidget->renderWindow()->GetInteractor()->Render();
 }
 
 
@@ -777,7 +777,7 @@ void QVTKStructure::ExportView2Image()
 		return;
 
 	vtkWindowToImageFilter* filter = vtkWindowToImageFilter::New();
-	filter->SetInput(VTKWidget->GetRenderWindow());
+	filter->SetInput(VTKWidget->renderWindow());
 
 	vtkPNGWriter* png_writer= vtkPNGWriter::New();
 	png_writer->SetInputConnection(filter->GetOutputPort());
