--- vcl/qt5/QtInstance.cxx.orig	2023-11-23 12:14:48 UTC
+++ vcl/qt5/QtInstance.cxx
@@ -220,7 +220,8 @@ QtInstance::QtInstance(std::unique_ptr<QApplication>& 
 
 QtInstance::QtInstance(std::unique_ptr<QApplication>& pQApp)
     : SalGenericInstance(std::make_unique<QtYieldMutex>())
-    , m_bUseCairo(nullptr == getenv("SAL_VCL_QT_USE_QFONT"))
+//    , m_bUseCairo(nullptr == getenv("SAL_VCL_QT_USE_QFONT"))
+    , m_bUseCairo(true) // (nullptr != getenv("SAL_VCL_QT5_USE_CAIRO"));
     , m_pTimer(nullptr)
     , m_bSleeping(false)
     , m_pQApplication(std::move(pQApp))
@@ -492,7 +493,7 @@ QtInstance::createPicker(css::uno::Reference<css::uno:
     {
         SolarMutexGuard g;
         rtl::Reference<QtFilePicker> pPicker;
-        RunInMainThread([&, this]() { pPicker = createPicker(context, eMode); });
+        RunInMainThread([&pPicker, this, context, eMode]() { pPicker = createPicker(context, eMode); });
         assert(pPicker);
         return pPicker;
     }
