--- electron/shell/browser/native_window.cc.orig	2026-05-08 13:54:01 UTC
+++ electron/shell/browser/native_window.cc
@@ -166,7 +166,7 @@ void NativeWindow::InitFromOptions(const gin_helper::D
   } else if (bool center; options.Get(options::kCenter, &center) && center) {
     Center();
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (bool val; options.Get(options::kClosable, &val))
     SetClosable(val);
 #endif
