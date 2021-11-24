--- chrome/browser/flag_descriptions.cc.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -5007,7 +5007,7 @@ const char kEnableNewBadgeOnMenuItemsDescription[] =
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 
 const char kEnableOopPrintDriversName[] =
@@ -5040,20 +5040,20 @@ const char kRemoteCopyProgressNotificationDescription[
     "Enables progress notifications to be shown for the remote copy feature "
     "when receiving a message.";
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 
 const char kDirectManipulationStylusName[] = "Direct Manipulation Stylus";
 const char kDirectManipulationStylusDescription[] =
     "If enabled, Chrome will scroll web pages on stylus drag.";
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
         // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kCommanderName[] = "Commander";
 const char kCommanderDescription[] =
@@ -5069,7 +5069,7 @@ const char kDesktopDetailedLanguageSettingsName[] =
 const char kDesktopDetailedLanguageSettingsDescription[] =
     "Enable the new detailed language settings page";
 
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS) || defined(OS_LINUX)
 #if BUILDFLAG(USE_TCMALLOC)
@@ -5096,20 +5096,20 @@ const char kWebShareDescription[] =
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
 const char kEnableEphemeralGuestProfilesOnDesktopName[] =
     "Enable ephemeral Guest profiles on Desktop";
 const char kEnableEphemeralGuestProfilesOnDesktopDescription[] =
     "Enables ephemeral Guest profiles on Windows, Linux, and Mac.";
-#endif  // defined(OS_WIN) || (defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || (defined(OS_LINUX) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_MAC)
 
-#if defined(OS_LINUX) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
 const char kUseOzonePlatformName[] = "Use ozone.";
 const char kUseOzonePlatformDescription[] =
     "Use the Ozone/X11 platform implementation on X11.";
-#endif  // defined(OS_LINUX) && defined(USE_OZONE)
+#endif  // (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
 
 // Feature flags --------------------------------------------------------------
 
@@ -5190,7 +5190,7 @@ const char kAutofillCreditCardUploadDescription[] =
 
 #endif  // defined(TOOLKIT_VIEWS) || defined(OS_ANDROID)
 
-#if !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 const char kSendWebUIJavaScriptErrorReportsName[] =
     "Send WebUI JavaScript Error Reports";
 const char kSendWebUIJavaScriptErrorReportsDescription[] =
@@ -5199,7 +5199,7 @@ const char kSendWebUIJavaScriptErrorReportsDescription
     "will be sent to Google.";
 #endif
 
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
 const char kUIDebugToolsName[] = "Debugging tools for UI";
 const char kUIDebugToolsDescription[] =
