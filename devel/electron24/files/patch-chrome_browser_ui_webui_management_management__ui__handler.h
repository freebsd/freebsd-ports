--- chrome/browser/ui/webui/management/management_ui_handler.h.orig	2023-03-30 00:33:44 UTC
+++ chrome/browser/ui/webui/management/management_ui_handler.h
@@ -24,7 +24,7 @@
 #include "extensions/common/extension_id.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Constants defining the IDs for the localized strings sent to the page as
 // load time data.
 extern const char kManagementScreenCaptureEvent[];
