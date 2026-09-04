--- vcl/qt5/QtInstance.cxx.orig	2026-06-16 11:40:38 UTC
+++ vcl/qt5/QtInstance.cxx
@@ -571,7 +571,7 @@ QtInstance::createPicker(css::uno::Reference<css::uno:
     {
         SolarMutexGuard g;
         rtl::Reference<QtFilePicker> pPicker;
-        RunInMainThread([&, this]() { pPicker = createPicker(context, eMode); });
+        RunInMainThread([&pPicker, this, context, eMode]() { pPicker = createPicker(context, eMode); });
         assert(pPicker);
         return pPicker;
     }
