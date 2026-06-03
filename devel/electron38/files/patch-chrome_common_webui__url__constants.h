--- chrome/common/webui_url_constants.h.orig	2025-08-26 20:49:50 UTC
+++ chrome/common/webui_url_constants.h
@@ -557,12 +557,12 @@ inline constexpr char kChromeUIOsUrlAppURL[] = "chrome
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIDiscardsHost[] = "discards";
 inline constexpr char kChromeUIDiscardsURL[] = "chrome://discards/";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIWebAppSettingsHost[] = "app-settings";
 inline constexpr char kChromeUIWebAppSettingsURL[] = "chrome://app-settings/";
 inline constexpr char kChromeUIWhatsNewHost[] = "whats-new";
@@ -574,11 +574,11 @@ inline constexpr char kChromeUILinuxProxyConfigHost[] 
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUISandboxHost[] = "sandbox";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIBrowserSwitchHost[] = "browser-switch";
 inline constexpr char kChromeUIBrowserSwitchURL[] = "chrome://browser-switch/";
 inline constexpr char kChromeUIIntroDefaultBrowserSubPage[] = "default-browser";
@@ -603,7 +603,7 @@ inline constexpr char kChromeUIHistorySyncOptinURL[] =
     "chrome://history-sync-optin/";
 #endif
 
-#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_CHROMEOS)) && \
      defined(TOOLKIT_VIEWS)) ||                         \
     defined(USE_AURA)
 inline constexpr char kChromeUITabModalConfirmDialogHost[] =
