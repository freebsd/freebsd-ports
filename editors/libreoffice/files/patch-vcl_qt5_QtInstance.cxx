--- vcl/qt5/QtInstance.cxx.orig	2023-07-28 18:13:49 UTC
+++ vcl/qt5/QtInstance.cxx
@@ -492,7 +492,7 @@ QtInstance::createPicker(css::uno::Reference<css::uno:
     {
         SolarMutexGuard g;
         rtl::Reference<QtFilePicker> pPicker;
-        RunInMainThread([&, this]() { pPicker = createPicker(context, eMode); });
+        RunInMainThread([&pPicker, this, context, eMode]() { pPicker = createPicker(context, eMode); });
         assert(pPicker);
         return pPicker;
     }
@@ -751,7 +751,7 @@ VCLPLUG_QT_PUBLIC SalInstance* create_SalInstance()
 extern "C" {
 VCLPLUG_QT_PUBLIC SalInstance* create_SalInstance()
 {
-    static const bool bUseCairo = (nullptr == getenv("SAL_VCL_QT_USE_QFONT"));
+    static const bool bUseCairo = true; // (nullptr != getenv("SAL_VCL_QT5_USE_CAIRO"));
 
     std::unique_ptr<char* []> pFakeArgv;
     std::unique_ptr<int> pFakeArgc;
