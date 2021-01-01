--- chrome/browser/flag_descriptions.h.orig	2019-12-12 12:39:10 UTC
+++ chrome/browser/flag_descriptions.h
@@ -20,9 +20,9 @@
 #include "ui/android/buildflags.h"
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 // This file declares strings used in chrome://flags. These messages are not
 // translated, because instead of end-users they target Chromium developers and
@@ -2181,7 +2181,7 @@ extern const char kZeroStateFilesDescription[];
 
 #endif  // #if defined(OS_CHROMEOS)
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kTerminalSystemAppName[];
 extern const char kTerminalSystemAppDescription[];
 
@@ -2190,7 +2190,7 @@ extern const char kDynamicTcmallocName[];
 extern const char kDynamicTcmallocDescription[];
 #endif  // BUILDFLAG(USE_TCMALLOC)
 
-#endif  // #if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#endif  // #if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
 
 // All views-based platforms --------------------------------------------------
 
@@ -2209,14 +2209,14 @@ extern const char kReopenTabInProductHelpDescription[]
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 extern const char kWebGL2ComputeContextName[];
 extern const char kWebGL2ComputeContextDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 
 extern const char kClickToCallContextMenuForSelectedTextName[];
@@ -2225,10 +2225,10 @@ extern const char kClickToCallContextMenuForSelectedTe
 extern const char kClickToCallUIName[];
 extern const char kClickToCallUIDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 extern const char kDirectManipulationStylusName[];
 extern const char kDirectManipulationStylusDescription[];
@@ -2242,7 +2242,7 @@ extern const char kProfileMenuRevampDescription[];
 extern const char kSyncClipboardServiceName[];
 extern const char kSyncClipboardServiceDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
@@ -2333,12 +2333,12 @@ extern const char kWebrtcPipeWireCapturerDescription[]
 
 #endif  // #if defined(WEBRTC_USE_PIPEWIRE)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 extern const char kEnableDbusAndX11StatusIconsName[];
 extern const char kEnableDbusAndX11StatusIconsDescription[];
 
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 // ============================================================================
 // Don't just add flags to the end, put them in the right section in
