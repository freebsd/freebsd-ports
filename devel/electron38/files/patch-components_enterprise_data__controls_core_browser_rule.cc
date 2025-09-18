--- components/enterprise/data_controls/core/browser/rule.cc.orig	2025-08-26 20:49:50 UTC
+++ components/enterprise/data_controls/core/browser/rule.cc
@@ -105,7 +105,7 @@ bool IgnoreRestriction(Rule::Restriction restriction) 
 // a type of restriction should be applied or not, check it here.
 bool IgnoreRestriction(Rule::Restriction restriction) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (restriction == Rule::Restriction::kFileDownload) {
     return !base::FeatureList::IsEnabled(kEnableDownloadDataControlsDesktop);
   }
@@ -538,7 +538,7 @@ bool Rule::AddUnsupportedAttributeErrors(
               },
           },
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
@@ -617,7 +617,7 @@ bool Rule::AddUnsupportedRestrictionErrors(
           },
 #endif  // BUILDFLAG(ENTERPRISE_SCREENSHOT_PROTECTION)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
