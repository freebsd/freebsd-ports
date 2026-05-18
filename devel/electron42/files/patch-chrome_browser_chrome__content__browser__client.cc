--- chrome/browser/chrome_content_browser_client.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -601,7 +601,7 @@
 #include "third_party/cros_system_api/switches/chrome_switches.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crash_switches.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -612,7 +612,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -1528,7 +1528,7 @@ void ChromeContentBrowserClient::RegisterLocalStatePre
   registry->RegisterBooleanPref(prefs::kDataURLWhitespacePreservationEnabled,
                                 true);
   registry->RegisterBooleanPref(prefs::kEnableUnsafeSwiftShader, false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kOutOfProcessSystemDnsResolutionEnabled,
                                 true);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
@@ -1795,7 +1795,7 @@ ChromeContentBrowserClient::GetStoragePartitionConfigF
 
 #if BUILDFLAG(ENABLE_EXTENSIONS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::SiteIsolationPolicy::ShouldUrlUseApplicationIsolationLevel(
           browser_context, site)) {
     CHECK(url::Origin::Create(site).scheme() == webapps::kIsolatedAppScheme);
@@ -2670,7 +2670,7 @@ bool ChromeContentBrowserClient::ShouldUrlUseApplicati
     const GURL& url) {
 #if BUILDFLAG(ENABLE_EXTENSIONS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
   if (!content::AreIsolatedWebAppsEnabled(browser_context)) {
     return false;
@@ -2798,7 +2798,9 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
 void ChromeContentBrowserClient::AppendExtraCommandLineSwitches(
     base::CommandLine* command_line,
     int child_process_id) {
+#if !BUILDFLAG(IS_BSD)
   crash_keys::AppendStringAnnotationsCommandLineSwitch(command_line);
+#endif
 #if BUILDFLAG(IS_MAC)
   std::unique_ptr<metrics::ClientInfo> client_info =
       GoogleUpdateSettings::LoadMetricsClientInfo();
@@ -2807,7 +2809,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
                                     client_info->client_id);
   }
 #elif BUILDFLAG(IS_POSIX)
-#if !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
   pid_t pid;
   if (crash_reporter::GetHandlerSocket(nullptr, &pid)) {
     command_line->AppendSwitchASCII(
@@ -3145,7 +3147,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Opt into a hardened stack canary mitigation if it hasn't already been
   // force-disabled.
   if (!browser_command_line.HasSwitch(switches::kChangeStackGuardOnFork)) {
@@ -4157,7 +4159,7 @@ std::optional<SkColor> GetRootScrollbarThemeColor(WebC
 
 std::optional<SkColor> GetRootScrollbarThemeColor(WebContents* web_contents) {
   bool root_scrollbar_follows_browser_theme = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   root_scrollbar_follows_browser_theme = base::FeatureList::IsEnabled(
       blink::features::kRootScrollbarFollowsBrowserTheme);
 #endif
@@ -5155,7 +5157,7 @@ void ChromeContentBrowserClient::GetAdditionalAllowedS
   additional_allowed_schemes->push_back(content::kChromeUIScheme);
   additional_allowed_schemes->push_back(content::kChromeUIUntrustedScheme);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   additional_allowed_schemes->push_back(webapps::kIsolatedAppScheme);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -5209,7 +5211,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -6107,7 +6109,7 @@ ChromeContentBrowserClient::CreateNonNetworkNavigation
   }
 #endif  // BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (scheme == webapps::kIsolatedAppScheme) {
     if (content::AreIsolatedWebAppsEnabled(browser_context) &&
         !browser_context->ShutdownStarted()) {
@@ -6133,7 +6135,7 @@ void ChromeContentBrowserClient::
   DCHECK(factories);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::AreIsolatedWebAppsEnabled(browser_context) &&
       !browser_context->ShutdownStarted()) {
     factories->emplace(webapps::kIsolatedAppScheme,
@@ -6162,7 +6164,7 @@ void ChromeContentBrowserClient::
   DCHECK(factories);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::AreIsolatedWebAppsEnabled(browser_context) &&
       !browser_context->ShutdownStarted()) {
     factories->emplace(webapps::kIsolatedAppScheme,
@@ -6435,7 +6437,7 @@ void ChromeContentBrowserClient::
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   {
     auto* rph = content::RenderProcessHost::FromID(render_process_id);
     content::BrowserContext* browser_context = rph->GetBrowserContext();
@@ -7041,7 +7043,7 @@ bool ChromeContentBrowserClient::HandleExternalProtoco
   CHECK(content::BrowserThread::CurrentlyOn(content::BrowserThread::UI));
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Handle the google-chrome:// scheme (and chromium://).
   // If the scheme is present, we strip it and navigate to the inner URL.
   // This avoids launching a new browser instance via the OS handler.
@@ -7170,7 +7172,7 @@ bool ChromeContentBrowserClient::HandleWebUI(
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
   // Rewrite chrome://settings/enhancedAutofill to chrome://settings/autofill.
   if (url->SchemeIs(content::kChromeUIScheme) &&
@@ -7459,7 +7461,7 @@ bool ChromeContentBrowserClient::ShouldRunOutOfProcess
 bool ChromeContentBrowserClient::ShouldRunOutOfProcessSystemDnsResolution() {
 // This enterprise policy is supported on Android, but the feature will not be
 // launched there.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // This is possibly called before `g_browser_process` is initialized.
   PrefService* local_state;
   if (g_browser_process) {
@@ -7885,7 +7887,7 @@ void ChromeContentBrowserClient::
     GrantAdditionalRequestPrivilegesToWorkerProcess(int child_id,
                                                     const GURL& script_url) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // IWA Service Workers need to be explicitly granted access to their origin
   // because isolated-app: isn't a web-safe scheme that can be accessed by
   // default.
@@ -8331,7 +8333,7 @@ ChromeContentBrowserClient::GetAlternativeErrorPageOve
     content::BrowserContext* browser_context,
     int32_t error_code) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (content::AreIsolatedWebAppsEnabled(browser_context) &&
       url.SchemeIs(webapps::kIsolatedAppScheme)) {
     content::mojom::AlternativeErrorPageOverrideInfoPtr
