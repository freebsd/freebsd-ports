--- extensions/browser/api/management/management_api.cc.orig	2025-06-30 07:04:30 UTC
+++ extensions/browser/api/management/management_api.cc
@@ -284,7 +284,7 @@ bool PlatformSupportsApprovalFlowForExtensions() {
 
 bool PlatformSupportsApprovalFlowForExtensions() {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
