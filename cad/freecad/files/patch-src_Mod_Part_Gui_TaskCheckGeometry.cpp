--- src/Mod/Part/Gui/TaskCheckGeometry.cpp.orig	2020-11-14 20:05:24 UTC
+++ src/Mod/Part/Gui/TaskCheckGeometry.cpp
@@ -418,11 +418,13 @@ void TaskCheckGeometryResults::goCheck()
     std::vector<Gui::SelectionSingleton::SelObj>::iterator it;
     ResultEntry *theRoot = new ResultEntry();
 
+#if OCC_VERSION_HEX < 0x070500
     Handle(Message_ProgressIndicator) theProgress = new BOPProgressIndicator(tr("Check geometry"), Gui::getMainWindow());
     theProgress->NewScope("BOP check...");
 #if OCC_VERSION_HEX >= 0x060900
     theProgress->Show();
 #endif
+#endif
 
     selectedCount = static_cast<int>(selection.size());
     for (it = selection.begin(); it != selection.end(); ++it)
@@ -484,11 +486,17 @@ void TaskCheckGeometryResults::goCheck()
             std::string label = "Checking ";
             label += feature->Label.getStrValue();
             label += "...";
+#if OCC_VERSION_HEX < 0x070500
             theProgress->NewScope(label.c_str());
             invalidShapes += goBOPSingleCheck(shape, theRoot, baseName, theProgress);
+#else
+            invalidShapes += goBOPSingleCheck(shape, theRoot, baseName, nullptr);
+#endif
+#if OCC_VERSION_HEX < 0x070500
             theProgress->EndScope();
             if (theProgress->UserBreak())
               break;
+#endif
           }
         }
     }
@@ -613,7 +621,7 @@ int TaskCheckGeometryResults::goBOPSingleCheck(const T
   //this is left for another time.
   TopoDS_Shape BOPCopy = BRepBuilderAPI_Copy(shapeIn).Shape();
   BOPAlgo_ArgumentAnalyzer BOPCheck;
-#if OCC_VERSION_HEX >= 0x060900
+#if OCC_VERSION_HEX >= 0x060900 && OCC_VERSION_HEX < 0x070500
   BOPCheck.SetProgressIndicator(theProgress);
 #else
   Q_UNUSED(theProgress);
@@ -961,6 +969,7 @@ TaskCheckGeometryDialog::~TaskCheckGeometryDialog()
 
 ////////////////////////////////////////////////////////////////////////////////////////////////
 
+#if OCC_VERSION_HEX < 0x070500
 BOPProgressIndicator::BOPProgressIndicator (const QString& title, QWidget* parent)
 {
     steps = 0;
@@ -1023,5 +1032,6 @@ Standard_Boolean BOPProgressIndicator::UserBreak()
 
     return Standard_False;
 }
+#endif
 
 #include "moc_TaskCheckGeometry.cpp"
