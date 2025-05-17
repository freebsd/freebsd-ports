--- ui/accessibility/accessibility_features.cc.orig	2025-04-22 20:15:27 UTC
+++ ui/accessibility/accessibility_features.cc
@@ -472,7 +472,7 @@ bool IsBlockRootWindowAccessibleNameChangeEventEnabled
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kWasmTtsComponentUpdaterEnabled,
              "WasmTtsComponentUpdaterEnabled",
              base::FEATURE_DISABLED_BY_DEFAULT);
