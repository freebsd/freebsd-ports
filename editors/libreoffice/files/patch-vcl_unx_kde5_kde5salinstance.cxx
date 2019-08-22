--- vcl/unx/kde5/KDE5SalInstance.cxx.orig
+++ vcl/unx/kde5/KDE5SalInstance.cxx
@@ -43,9 +43,9 @@
 SalFrame* KDE5SalInstance::CreateFrame(SalFrame* pParent, SalFrameStyleFlags nState)
 {
     SalFrame* pRet(nullptr);
-    RunInMainThread(std::function([&pRet, pParent, nState]() {
+    RunInMainThread([&pRet, pParent, nState]() {
         pRet = new KDE5SalFrame(static_cast<KDE5SalFrame*>(pParent), nState, true);
-    }));
+    });
     assert(pRet);
     return pRet;
 }
@@ -65,7 +65,7 @@
     {
         SolarMutexGuard g;
         Qt5FilePicker* pPicker;
-        RunInMainThread(std::function([&, this]() { pPicker = createPicker(context, eMode); }));
+        RunInMainThread([&, this]() { pPicker = createPicker(context, eMode); });
         assert(pPicker);
         return pPicker;
     }
