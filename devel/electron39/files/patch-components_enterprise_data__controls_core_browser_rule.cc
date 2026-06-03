--- components/enterprise/data_controls/core/browser/rule.cc.orig	2025-10-21 20:19:54 UTC
+++ components/enterprise/data_controls/core/browser/rule.cc
@@ -531,7 +531,7 @@ bool Rule::AddUnsupportedAttributeErrors(
               },
           },
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
@@ -610,7 +610,7 @@ bool Rule::AddUnsupportedRestrictionErrors(
           },
 #endif  // BUILDFLAG(ENTERPRISE_SCREENSHOT_PROTECTION)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
