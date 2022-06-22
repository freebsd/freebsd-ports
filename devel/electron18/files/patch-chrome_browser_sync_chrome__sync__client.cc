--- chrome/browser/sync/chrome_sync_client.cc.orig	2022-05-19 05:17:38 UTC
+++ chrome/browser/sync/chrome_sync_client.cc
@@ -412,7 +412,7 @@ ChromeSyncClient::CreateDataTypeControllers(syncer::Sy
 
 // Chrome prefers OS provided spell checkers where they exist. So only sync the
 // custom dictionary on platforms that typically don't provide one.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Dictionary sync is enabled by default.
   if (GetPrefService()->GetBoolean(spellcheck::prefs::kSpellCheckEnable)) {
     controllers.push_back(
