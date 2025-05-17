--- chrome/browser/ui/webui/signin/profile_picker_handler.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/ui/webui/signin/profile_picker_handler.cc
@@ -165,7 +165,7 @@ base::Value::Dict CreateProfileEntry(const ProfileAttr
       IDS_PROFILE_PICKER_PROFILE_CARD_LABEL, local_profile_name);
   if (AccountInfo::IsManaged(entry->GetHostedDomain())) {
     profile_entry.Set("avatarBadge", "cr:domain");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (base::FeatureList::IsEnabled(
                  supervised_user::kShowKiteForSupervisedUsers) &&
              entry->IsSupervised()) {
