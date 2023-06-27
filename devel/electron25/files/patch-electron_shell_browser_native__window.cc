--- electron/shell/browser/native_window.cc.orig	2023-02-06 19:29:11 UTC
+++ electron/shell/browser/native_window.cc
@@ -196,7 +196,7 @@ void NativeWindow::InitFromOptions(const gin_helper::D
   } else {
     SetSizeConstraints(size_constraints);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool resizable;
   if (options.Get(options::kResizable, &resizable)) {
     SetResizable(resizable);
