--- electron/shell/browser/native_window.cc.orig	2025-04-04 05:26:44 UTC
+++ electron/shell/browser/native_window.cc
@@ -200,7 +200,7 @@ void NativeWindow::InitFromOptions(const gin_helper::D
   } else {
     SetSizeConstraints(size_constraints);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool closable;
   if (options.Get(options::kClosable, &closable)) {
     SetClosable(closable);
