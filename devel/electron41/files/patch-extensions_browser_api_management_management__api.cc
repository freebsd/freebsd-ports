--- extensions/browser/api/management/management_api.cc.orig	2025-10-21 20:19:54 UTC
+++ extensions/browser/api/management/management_api.cc
@@ -296,7 +296,7 @@ bool PlatformSupportsApprovalFlowForExtensions() {
 
 bool PlatformSupportsApprovalFlowForExtensions() {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
