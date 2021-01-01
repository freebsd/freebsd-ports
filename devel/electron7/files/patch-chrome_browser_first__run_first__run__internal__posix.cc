--- chrome/browser/first_run/first_run_internal_posix.cc.orig	2019-12-12 12:39:10 UTC
+++ chrome/browser/first_run/first_run_internal_posix.cc
@@ -45,7 +45,7 @@ enum class ForcedShowDialogState {
 ForcedShowDialogState g_forced_show_dialog_state =
     ForcedShowDialogState::kNotForced;
 
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
 // Returns whether the first run dialog should be shown. This is only true for
 // certain builds, and only if the user has not already set preferences. In a
 // real, official-build first run, initializes the default metrics reporting if
@@ -96,7 +96,7 @@ void ForceFirstRunDialogShownForTesting(bool shown) {
 }
 
 void DoPostImportPlatformSpecificTasks(Profile* profile) {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   if (!ShouldShowFirstRunDialog())
     return;
 
