--- electron/shell/browser/printing/printing_utils.cc.orig	2024-04-18 21:07:39 UTC
+++ electron/shell/browser/printing/printing_utils.cc
@@ -20,7 +20,7 @@
 #include <ApplicationServices/ApplicationServices.h>
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <gtk/gtk.h>
 #endif
 
