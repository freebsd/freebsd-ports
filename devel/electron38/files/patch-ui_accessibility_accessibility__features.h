--- ui/accessibility/accessibility_features.h.orig	2025-09-09 01:18:53 UTC
+++ ui/accessibility/accessibility_features.h
@@ -345,7 +345,7 @@ AX_BASE_EXPORT bool IsScreenAITestModeEnabled();
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(kScreenAITestMode);
 AX_BASE_EXPORT bool IsScreenAITestModeEnabled();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables advanced partition allocation checks in ScreenAI service.
 // TODO(crbug.com/418199684): Remove when the bug is fixed.
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(
@@ -372,7 +372,7 @@ AX_BASE_EXPORT bool IsBlockRootWindowAccessibleNameCha
 AX_BASE_EXPORT bool IsBlockRootWindowAccessibleNameChangeEventEnabled();
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Use the v3 version of the wasm tts engine component.
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(kWasmTtsComponentUpdaterV3Enabled);
 AX_BASE_EXPORT bool IsWasmTtsComponentUpdaterV3Enabled();
