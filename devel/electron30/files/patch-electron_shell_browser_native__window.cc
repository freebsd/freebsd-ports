--- electron/shell/browser/native_window.cc.orig	2024-07-09 23:10:34 UTC
+++ electron/shell/browser/native_window.cc
@@ -203,7 +203,7 @@ void NativeWindow::InitFromOptions(const gin_helper::D
   } else {
     SetSizeConstraints(size_constraints);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool closable;
   if (options.Get(options::kClosable, &closable)) {
     SetClosable(closable);
