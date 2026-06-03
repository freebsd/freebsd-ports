--- electron/shell/browser/native_window.cc.orig	2026-04-07 01:35:50 UTC
+++ electron/shell/browser/native_window.cc
@@ -192,7 +192,7 @@ void NativeWindow::InitFromOptions(const gin_helper::D
   } else if (bool center; options.Get(options::kCenter, &center) && center) {
     Center();
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (bool val; options.Get(options::kClosable, &val))
     SetClosable(val);
 #endif
