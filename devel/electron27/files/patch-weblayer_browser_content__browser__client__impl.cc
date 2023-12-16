--- weblayer/browser/content_browser_client_impl.cc.orig	2023-10-19 19:59:22 UTC
+++ weblayer/browser/content_browser_client_impl.cc
@@ -154,7 +154,7 @@
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "content/public/common/content_descriptors.h"
 #endif
 
@@ -1025,7 +1025,7 @@ SafeBrowsingService* ContentBrowserClientImpl::GetSafe
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void ContentBrowserClientImpl::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
