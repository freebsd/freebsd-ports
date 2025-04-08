--- chrome/browser/enterprise/util/managed_browser_utils.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/enterprise/util/managed_browser_utils.cc
@@ -222,7 +222,7 @@ void SetUserAcceptedAccountManagement(Profile* profile
           .GetProfileAttributesWithPath(profile->GetPath());
   if (entry) {
     entry->SetUserAcceptedAccountManagement(accepted);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     entry->SetEnterpriseProfileLabel(GetEnterpriseLabel(profile));
 #endif
   }
