--- electron/shell/browser/native_window.cc.orig	2023-06-27 15:34:12 UTC
+++ electron/shell/browser/native_window.cc
@@ -197,7 +197,7 @@ void NativeWindow::InitFromOptions(const gin_helper::D
   } else {
     SetSizeConstraints(size_constraints);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool resizable;
   if (options.Get(options::kResizable, &resizable)) {
     SetResizable(resizable);
