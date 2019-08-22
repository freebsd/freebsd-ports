--- vcl/qt5/Qt5Instance.cxx.orig	2019-08-21 22:22:13.996160000 +0800
+++ vcl/qt5/Qt5Instance.cxx	2019-08-21 22:30:33.169056000 +0800
@@ -413,7 +413,7 @@
     {
         SolarMutexGuard g;
         Qt5FilePicker* pPicker;
-        RunInMainThread(std::function([&, this]() { pPicker = createPicker(context, eMode); }));
+        RunInMainThread([&, this]() { pPicker = createPicker(context, eMode); });
         assert(pPicker);
         return pPicker;
     }
