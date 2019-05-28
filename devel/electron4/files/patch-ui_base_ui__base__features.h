--- ui/base/ui_base_features.h.orig	2019-03-15 06:38:27 UTC
+++ ui/base/ui_base_features.h
@@ -43,9 +43,9 @@ UI_BASE_EXPORT extern const base::Feature kTSFImeSuppo
 UI_BASE_EXPORT bool IsUsingWMPointerForTouch();
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 UI_BASE_EXPORT extern const base::Feature kDirectManipulationStylus;
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Used to have ash (Chrome OS system UI) run in its own process.
 // TODO(jamescook): Make flag only available in Chrome OS.
