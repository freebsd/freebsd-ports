--- chrome/app/chrome_main.cc.orig	2019-03-15 06:36:59 UTC
+++ chrome/app/chrome_main.cc
@@ -89,14 +89,14 @@ int ChromeMain(int argc, const char** argv) {
   ALLOW_UNUSED_LOCAL(command_line);
 
   // Chrome-specific process modes.
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
   if (command_line->HasSwitch(switches::kHeadless)) {
 #if defined(OS_MACOSX)
     SetUpBundleOverrides();
 #endif
     return headless::HeadlessShellMain(params);
   }
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
   int rv = content::ContentMain(params);
 
