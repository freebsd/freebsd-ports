--- vcl/qt5/Qt5Instance.cxx.orig	2020-05-13 11:19:20 UTC
+++ vcl/qt5/Qt5Instance.cxx
@@ -261,7 +261,13 @@ SalFrame* Qt5Instance::CreateChildFrame(SystemParentDa
 SalFrame* Qt5Instance::CreateFrame(SalFrame* pParent, SalFrameStyleFlags nStyle)
 {
     assert(!pParent || dynamic_cast<Qt5Frame*>(pParent));
-    return new Qt5Frame(static_cast<Qt5Frame*>(pParent), nStyle, m_bUseCairo);
+    SalFrame* pRet(nullptr);
+    bool bUseCairo = m_bUseCairo;
+    RunInMainThread([&pRet, pParent, nStyle, bUseCairo]() {
+        pRet = new Qt5Frame(static_cast<Qt5Frame*>(pParent), nStyle, bUseCairo);
+    });
+    assert(pRet);
+    return pRet;
 }
 
 void Qt5Instance::DestroyFrame(SalFrame* pFrame)
@@ -420,7 +426,7 @@ Qt5Instance::createPicker(css::uno::Reference<css::uno
     {
         SolarMutexGuard g;
         Qt5FilePicker* pPicker;
-        RunInMainThread([&, this]() { pPicker = createPicker(context, eMode); });
+        RunInMainThread([&pPicker, this, context, eMode]() { pPicker = createPicker(context, eMode); });
         assert(pPicker);
         return pPicker;
     }
@@ -624,7 +630,7 @@ std::unique_ptr<QApplication> Qt5Instance::CreateQAppl
 extern "C" {
 VCLPLUG_QT5_PUBLIC SalInstance* create_SalInstance()
 {
-    static const bool bUseCairo = (nullptr != getenv("SAL_VCL_QT5_USE_CAIRO"));
+    static const bool bUseCairo = true; // (nullptr != getenv("SAL_VCL_QT5_USE_CAIRO"));
 
     std::unique_ptr<char* []> pFakeArgv;
     std::unique_ptr<int> pFakeArgc;
