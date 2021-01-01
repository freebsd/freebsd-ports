--- chrome/browser/first_run/first_run_internal_posix.cc.orig	2019-03-15 06:37:03 UTC
+++ chrome/browser/first_run/first_run_internal_posix.cc
@@ -34,7 +34,7 @@ base::OnceClosure& GetBeforeShowFirstRunDialogHookForT
 namespace internal {
 namespace {
 
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
 // Returns whether the first run dialog should be shown. This is only true for
 // certain builds, and only if the user has not already set preferences. In a
 // real, official-build first run, initializes the default metrics reporting if
@@ -80,7 +80,7 @@ bool ShouldShowFirstRunDialog() {
 }  // namespace
 
 void DoPostImportPlatformSpecificTasks(Profile* profile) {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   if (!ShouldShowFirstRunDialog())
     return;
 
