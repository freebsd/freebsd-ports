--- vv/vvToolHistogram.cxx.orig	2025-04-17 12:54:38 UTC
+++ vv/vvToolHistogram.cxx
@@ -20,6 +20,9 @@
 #include <QShortcut>
 
 #include <algorithm>
+#include <fstream>
+#include <string>
+#include <iostream>
 
 // vv
 #include "vvToolHistogram.h"
@@ -94,8 +97,8 @@ vvToolHistogram::vvToolHistogram(vvMainWindowBase * pa
   chart->SetRenderEmpty(true);
   mView->GetScene()->AddItem(chart);
   mView->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
-  this->HistogramWidget->GetRenderWindow()->GetRenderers()->RemoveAllItems();
-  this->HistogramWidget->GetRenderWindow()->AddRenderer(mView->GetRenderer());
+  this->HistogramWidget->renderWindow()->GetRenderers()->RemoveAllItems();
+  this->HistogramWidget->renderWindow()->AddRenderer(mView->GetRenderer());
   HistogramWidget->show();
 
 #ifdef Q_OS_OSX
@@ -201,8 +204,8 @@ void vvToolHistogram::displayHistogram()
     chart->GetAxis(vtkAxis::LEFT)->SetTitle("#Voxels");
     chart->GetAxis(vtkAxis::BOTTOM)->SetTitle("Intensity");
 
-    this->HistogramWidget->GetRenderWindow()->GetRenderers()->RemoveAllItems();
-    this->HistogramWidget->GetRenderWindow()->AddRenderer(mView->GetRenderer());
+    this->HistogramWidget->renderWindow()->GetRenderers()->RemoveAllItems();
+    this->HistogramWidget->renderWindow()->AddRenderer(mView->GetRenderer());
     HistogramWidget->show();
 
     QApplication::restoreOverrideCursor();
@@ -300,10 +303,10 @@ void vvToolHistogram::InputIsSelected(vvSlicerManager 
   // Connect signals & slots
   vvToolHistogramCommand *smc = vvToolHistogramCommand::New();
   smc->mHist = this;
-  HistogramWidget->GetRenderWindow()->GetInteractor()->GetInteractorStyle()->AddObserver(vtkCommand::LeftButtonPressEvent, smc);
-  HistogramWidget->GetRenderWindow()->GetInteractor()->GetInteractorStyle()->AddObserver(vtkCommand::MouseMoveEvent, smc);
-  HistogramWidget->GetRenderWindow()->GetInteractor()->GetInteractorStyle()->AddObserver(vtkCommand::MouseWheelForwardEvent, smc);
-  HistogramWidget->GetRenderWindow()->GetInteractor()->GetInteractorStyle()->AddObserver(vtkCommand::MouseWheelBackwardEvent, smc);
+  HistogramWidget->renderWindow()->GetInteractor()->GetInteractorStyle()->AddObserver(vtkCommand::LeftButtonPressEvent, smc);
+  HistogramWidget->renderWindow()->GetInteractor()->GetInteractorStyle()->AddObserver(vtkCommand::MouseMoveEvent, smc);
+  HistogramWidget->renderWindow()->GetInteractor()->GetInteractorStyle()->AddObserver(vtkCommand::MouseWheelForwardEvent, smc);
+  HistogramWidget->renderWindow()->GetInteractor()->GetInteractorStyle()->AddObserver(vtkCommand::MouseWheelBackwardEvent, smc);
   smc->Delete();
 
 }
@@ -443,7 +446,7 @@ void vvToolHistogram::SaveAs()
         std::ofstream fileOpen(mTextFileName.c_str(), std::ofstream::trunc);
   
         if(!fileOpen) {
-            cerr << "Error during saving" << endl;
+            std::cerr << "Error during saving" << std::endl;
             QApplication::restoreOverrideCursor();
             close();
             return;
