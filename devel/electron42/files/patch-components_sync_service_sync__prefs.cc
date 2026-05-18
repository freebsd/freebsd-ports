--- components/sync/service/sync_prefs.cc.orig	2026-04-28 21:06:17 UTC
+++ components/sync/service/sync_prefs.cc
@@ -866,7 +866,7 @@ bool SyncPrefs::MaybeMigratePrefsForSyncToSigninPart1(
           update_selected_types_dict->EnsureDict(
               signin::GaiaIdHash::FromGaiaId(gaia_id).ToBase64());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Preserve the user's existing enabled state for Bookmarks, Reading List,
       // and Preferences. Otherwise, use the default value, which will be true
       // after `kReplaceSyncPromosWithSignInPromos`.
