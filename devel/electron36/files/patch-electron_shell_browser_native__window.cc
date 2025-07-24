--- electron/shell/browser/native_window.cc.orig	2025-07-22 07:50:49 UTC
+++ electron/shell/browser/native_window.cc
@@ -178,7 +178,7 @@ void NativeWindow::InitFromOptions(const gin_helper::D
   } else {
     SetSizeConstraints(size_constraints);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (bool val; options.Get(options::kClosable, &val))
     SetClosable(val);
 #endif
