--- electron/shell/browser/api/electron_api_base_window.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/browser/api/electron_api_base_window.cc
@@ -57,7 +57,7 @@
 #include "shell/browser/ui/views/win_frame_view.h"
 #include "shell/browser/ui/win/taskbar_host.h"
 #include "ui/base/win/shell.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/ui/views/electron_frame_view_linux.h"
 #include "ui/gfx/image/image_skia.h"
 #endif
@@ -1178,7 +1178,7 @@ void BaseWindow::SetIconImpl(v8::Isolate* isolate,
   static_cast<NativeWindowViews*>(window_.get())
       ->SetIcon(native_image->GetHICON(GetSystemMetrics(SM_CXSMICON)),
                 native_image->GetHICON(GetSystemMetrics(SM_CXICON)));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static_cast<NativeWindowViews*>(window_.get())
       ->SetIcon(native_image->image().AsImageSkia());
 #endif
@@ -1279,7 +1279,7 @@ v8::Local<v8::Value> BaseWindow::GetAccentColor() cons
 }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BaseWindow::SetTitleBarOverlay(const gin_helper::Dictionary& options,
                                     gin::Arguments* args) {
   static_cast<NativeWindowViews*>(window_.get())
@@ -1600,7 +1600,7 @@ void BaseWindow::BuildPrototype(v8::Isolate* isolate,
       .SetMethod<&BaseWindow::SetThumbnailToolTip>("setThumbnailToolTip")
       .SetMethod<&BaseWindow::SetAppDetails>("setAppDetails")
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       .SetMethod<&BaseWindow::SetTitleBarOverlay>("setTitleBarOverlay")
 #endif
       .SetProperty<&BaseWindow::GetID>("id");
