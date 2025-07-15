--- components/sync/service/sync_prefs.cc.orig	2025-06-30 07:04:30 UTC
+++ components/sync/service/sync_prefs.cc
@@ -776,7 +776,7 @@ bool SyncPrefs::IsTypeSupportedInTransportMode(UserSel
       // transport mode everywhere.
       return true;
     case UserSelectableType::kHistory:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return base::FeatureList::IsEnabled(kReplaceSyncPromosWithSignInPromos) ||
              base::FeatureList::IsEnabled(switches::kEnableHistorySyncOptin);
 #else
