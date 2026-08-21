--- electron/shell/browser/native_window.cc.orig	2026-08-18 19:28:27 UTC
+++ electron/shell/browser/native_window.cc
@@ -33,7 +33,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "shell/browser/ui/views/frameless_view.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/ui/views/electron_frame_view_linux.h"
 #endif
 
@@ -184,7 +184,7 @@ void NativeWindow::InitFromOptions(const gin_helper::D
   } else if (bool center; options.Get(options::kCenter, &center) && center) {
     Center();
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (bool val; options.Get(options::kClosable, &val))
     SetClosable(val);
 #endif
