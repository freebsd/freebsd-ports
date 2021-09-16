--- vcl/qt5/Qt5Instance.cxx.orig	2021-09-08 17:53:20 UTC
+++ vcl/qt5/Qt5Instance.cxx
@@ -476,7 +476,7 @@ Qt5Instance::createPicker(css::uno::Reference<css::uno
     {
         SolarMutexGuard g;
         rtl::Reference<Qt5FilePicker> pPicker;
-        RunInMainThread([&, this]() { pPicker = createPicker(context, eMode); });
+        RunInMainThread([&pPicker, this, context, eMode]() { pPicker = createPicker(context, eMode); });
         assert(pPicker);
         return pPicker;
     }
@@ -681,7 +681,7 @@ std::unique_ptr<QApplication> Qt5Instance::CreateQAppl
 extern "C" {
 VCLPLUG_QT5_PUBLIC SalInstance* create_SalInstance()
 {
-    static const bool bUseCairo = (nullptr != getenv("SAL_VCL_QT5_USE_CAIRO"));
+    static const bool bUseCairo = true; // (nullptr != getenv("SAL_VCL_QT5_USE_CAIRO"));
 
     std::unique_ptr<char* []> pFakeArgv;
     std::unique_ptr<int> pFakeArgc;
