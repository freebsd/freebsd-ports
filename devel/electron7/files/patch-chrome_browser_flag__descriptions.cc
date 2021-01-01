--- chrome/browser/flag_descriptions.cc.orig	2019-12-12 12:39:10 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -3637,7 +3637,7 @@ const char kZeroStateFilesDescription[] =
 
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 const char kTerminalSystemAppName[] = "Terminal System App";
 const char kTerminalSystemAppDescription[] =
     "Enables the Terminal System App at chrome://terminal which is used for "
@@ -3650,7 +3650,7 @@ const char kDynamicTcmallocDescription[] =
     "utilization.";
 #endif  // BUILDFLAG(USE_TCMALLOC)
 
-#endif  // #if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#endif  // #if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 
 // All views-based platforms --------------------------------------------------
 
@@ -3675,15 +3675,15 @@ const char kReopenTabInProductHelpDescription[] =
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 const char kWebGL2ComputeContextName[] = "WebGL 2.0 Compute";
 const char kWebGL2ComputeContextDescription[] =
     "Enable the use of WebGL 2.0 Compute API.";
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||  \
     defined(OS_CHROMEOS)
 
 const char kClickToCallContextMenuForSelectedTextName[] =
@@ -3698,10 +3698,10 @@ const char kClickToCallUIDescription[] =
     "Enables click to call feature signals to be handled on desktop by showing "
     "a list of user's available devices with telephony functionality.";
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kDirectManipulationStylusName[] = "Direct Manipulation Stylus";
 const char kDirectManipulationStylusDescription[] =
@@ -3720,7 +3720,7 @@ const char kSyncClipboardServiceName[] = "Sync Clipboa
 const char kSyncClipboardServiceDescription[] =
     "Enables clipboard syncing via Chrome Sync.";
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
@@ -3830,7 +3830,7 @@ extern const char kWebrtcPipeWireCapturerDescription[]
 
 #endif  // #if defined(WEBRTC_USE_PIPEWIRE)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 const char kEnableDbusAndX11StatusIconsName[] =
     "Enable DBus and X11 status icons";
@@ -3839,7 +3839,7 @@ const char kEnableDbusAndX11StatusIconsDescription[] =
     "(X11) implementations of status icons.  Otherwise, uses libappindicator's "
     "and GTK's implementations.";
 
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 const char kAvoidFlashBetweenNavigationName[] =
     "Enable flash avoidance between same-origin navigations";
