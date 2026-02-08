--- chrome/browser/platform_util_linux.cc.orig	2026-01-07 00:52:53 UTC
+++ chrome/browser/platform_util_linux.cc
@@ -297,7 +297,9 @@ void OnLaunchOptionsCreated(const std::string& command
   argv.push_back(command);
   argv.push_back(arg);
   options.current_directory = working_directory;
+#if !BUILDFLAG(IS_BSD)
   options.allow_new_privs = true;
+#endif
   // xdg-open can fall back on mailcap which eventually might plumb through
   // to a command that needs a terminal.  Set the environment variable telling
   // it that we definitely don't have a terminal available and that it should
