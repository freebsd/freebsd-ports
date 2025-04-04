- workaround for https://gitlab.kitware.com/vtk/vtk/-/issues/18683

--- src/IVtkDraw/IVtkDraw_Interactor.cxx.orig	2025-02-17 22:00:23 UTC
+++ src/IVtkDraw/IVtkDraw_Interactor.cxx
@@ -173,6 +173,12 @@ void IVtkDraw_Interactor::Initialize()
   aSize             = aRenWin->GetSize();
   aRenWin->Start();
 #endif
+#ifdef Status
+#undef Status
+#endif
+#ifdef Success
+#undef Success
+#endif
 
   this->Enable();
   this->Size[0] = aSize[0];
