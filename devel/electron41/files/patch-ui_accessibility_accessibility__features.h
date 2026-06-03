--- ui/accessibility/accessibility_features.h.orig	2026-03-13 16:54:03 UTC
+++ ui/accessibility/accessibility_features.h
@@ -383,7 +383,7 @@ AX_BASE_EXPORT bool IsScreenAITestModeEnabled();
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(kScreenAITestMode);
 AX_BASE_EXPORT bool IsScreenAITestModeEnabled();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables advanced partition allocation checks in ScreenAI service.
 // TODO(crbug.com/418199684): Remove when the bug is fixed.
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(
@@ -410,7 +410,7 @@ AX_BASE_EXPORT bool IsBlockRootWindowAccessibleNameCha
 AX_BASE_EXPORT bool IsBlockRootWindowAccessibleNameChangeEventEnabled();
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Disable the wasm tts engine component to use dev version local extension
 // files.
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(kWasmTtsEngineAutoInstallDisabled);
