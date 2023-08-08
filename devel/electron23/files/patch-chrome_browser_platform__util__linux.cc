--- chrome/browser/platform_util_linux.cc.orig	2023-02-01 18:43:11 UTC
+++ chrome/browser/platform_util_linux.cc
@@ -296,7 +296,9 @@ void RunCommand(const std::string& command,
 
   base::LaunchOptions options;
   options.current_directory = working_directory;
+#if !defined(OS_BSD)
   options.allow_new_privs = true;
+#endif
   // xdg-open can fall back on mailcap which eventually might plumb through
   // to a command that needs a terminal.  Set the environment variable telling
   // it that we definitely don't have a terminal available and that it should
