--- electron/shell/browser/api/electron_api_base_window.cc.orig	2023-09-20 06:48:06 UTC
+++ electron/shell/browser/api/electron_api_base_window.cc
@@ -1067,7 +1067,7 @@ void BaseWindow::SetIconImpl(v8::Isolate* isolate,
   static_cast<NativeWindowViews*>(window_.get())
       ->SetIcon(native_image->GetHICON(GetSystemMetrics(SM_CXSMICON)),
                 native_image->GetHICON(GetSystemMetrics(SM_CXICON)));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static_cast<NativeWindowViews*>(window_.get())
       ->SetIcon(native_image->image().AsImageSkia());
 #endif
