--- chrome/browser/devtools/remote_debugging_server.cc.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/devtools/remote_debugging_server.cc
@@ -48,7 +48,7 @@ bool g_tethering_enabled = false;
 
 bool g_tethering_enabled = false;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool g_enable_default_user_data_dir_check_for_chromium_branding_for_testing =
     false;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -166,7 +166,7 @@ IsRemoteDebuggingAllowed(const std::optional<bool>& is
     return base::unexpected(
         RemoteDebuggingServer::NotStartedReason::kDisabledByPolicy);
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   constexpr bool default_user_data_dir_check_enabled = true;
 #else
@@ -293,7 +293,7 @@ void RemoteDebuggingServer::EnableTetheringForDebug() 
   g_tethering_enabled = true;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void RemoteDebuggingServer::EnableDefaultUserDataDirCheckForTesting() {
   g_enable_default_user_data_dir_check_for_chromium_branding_for_testing = true;
