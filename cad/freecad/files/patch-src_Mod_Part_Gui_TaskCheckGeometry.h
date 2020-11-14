--- src/Mod/Part/Gui/TaskCheckGeometry.h.orig	2020-11-14 20:12:50 UTC
+++ src/Mod/Part/Gui/TaskCheckGeometry.h
@@ -27,6 +27,7 @@
 #include <BRepCheck_Analyzer.hxx>
 #include <BRepCheck_Status.hxx>
 #include <Message_ProgressIndicator.hxx>
+#include <Standard_Version.hxx>
 #include <TopTools_MapOfShape.hxx>
 #include <Gui/TaskView/TaskDialog.h>
 #include <Gui/TaskView/TaskView.h>
@@ -147,6 +148,7 @@ class TaskCheckGeometryDialog : public Gui::TaskView::
     QTextEdit *contentLabel;
 };
 
+#if OCC_VERSION_HEX < 0x070500
 class BOPProgressIndicator : public Message_ProgressIndicator
 {
 public:
@@ -162,6 +164,7 @@ class BOPProgressIndicator : public Message_ProgressIn
     QTime time;
     QProgressDialog* myProgress;
 };
+#endif
 
 }
 
