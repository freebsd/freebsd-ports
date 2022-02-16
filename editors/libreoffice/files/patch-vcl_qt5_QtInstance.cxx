--- vcl/qt5/QtInstance.cxx.orig	2022-01-26 14:35:29 UTC
+++ vcl/qt5/QtInstance.cxx
@@ -479,7 +479,7 @@ QtInstance::createPicker(css::uno::Reference<css::uno:
     {
         SolarMutexGuard g;
         rtl::Reference<QtFilePicker> pPicker;
-        RunInMainThread([&, this]() { pPicker = createPicker(context, eMode); });
+        RunInMainThread([&pPicker, this, context, eMode]() { pPicker = createPicker(context, eMode); });
         assert(pPicker);
         return pPicker;
     }
@@ -689,7 +689,7 @@ std::unique_ptr<QApplication> QtInstance::CreateQAppli
 extern "C" {
 VCLPLUG_QT_PUBLIC SalInstance* create_SalInstance()
 {
-    static const bool bUseCairo = (nullptr != getenv("SAL_VCL_QT5_USE_CAIRO"));
+    static const bool bUseCairo = true; // (nullptr != getenv("SAL_VCL_QT5_USE_CAIRO"));
 
     std::unique_ptr<char* []> pFakeArgv;
     std::unique_ptr<int> pFakeArgc;
