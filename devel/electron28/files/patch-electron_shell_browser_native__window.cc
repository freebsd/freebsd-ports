--- electron/shell/browser/native_window.cc.orig	2023-12-04 18:19:02 UTC
+++ electron/shell/browser/native_window.cc
@@ -205,7 +205,7 @@ void NativeWindow::InitFromOptions(const gin_helper::D
   } else {
     SetSizeConstraints(size_constraints);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool closable;
   if (options.Get(options::kClosable, &closable)) {
     SetClosable(closable);
