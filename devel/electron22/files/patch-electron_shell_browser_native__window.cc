--- electron/shell/browser/native_window.cc.orig	2023-01-31 17:36:58 UTC
+++ electron/shell/browser/native_window.cc
@@ -189,7 +189,7 @@ void NativeWindow::InitFromOptions(const gin_helper::D
   } else {
     SetSizeConstraints(size_constraints);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool resizable;
   if (options.Get(options::kResizable, &resizable)) {
     SetResizable(resizable);
