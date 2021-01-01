--- chrome/browser/native_file_system/chrome_native_file_system_permission_context.cc.orig	2019-12-12 12:39:11 UTC
+++ chrome/browser/native_file_system/chrome_native_file_system_permission_context.cc
@@ -225,7 +225,7 @@ const struct {
     {base::DIR_APP_DATA, nullptr, true},
     {base::DIR_HOME, FILE_PATH_LITERAL("Library"), true},
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // On Linux also block access to devices via /dev, as well as security
     // sensitive data in /sys and /proc.
     {kNoBasePathKey, FILE_PATH_LITERAL("/dev"), true},
