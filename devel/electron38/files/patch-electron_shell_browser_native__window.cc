--- electron/shell/browser/native_window.cc.orig	2025-11-13 22:57:06 UTC
+++ electron/shell/browser/native_window.cc
@@ -185,7 +185,7 @@ void NativeWindow::InitFromOptions(const gin_helper::D
   } else {
     SetSizeConstraints(size_constraints);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (bool val; options.Get(options::kClosable, &val))
     SetClosable(val);
 #endif
