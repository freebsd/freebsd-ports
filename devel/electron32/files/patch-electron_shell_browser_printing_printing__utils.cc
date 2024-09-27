--- electron/shell/browser/printing/printing_utils.cc.orig	2024-08-20 22:47:02 UTC
+++ electron/shell/browser/printing/printing_utils.cc
@@ -28,7 +28,7 @@
 #include <ApplicationServices/ApplicationServices.h>
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <gtk/gtk.h>
 #endif
 
