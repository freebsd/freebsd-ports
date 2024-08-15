--- chrome/browser/platform_util_linux.cc.orig	2024-04-15 20:33:47 UTC
+++ chrome/browser/platform_util_linux.cc
@@ -300,7 +300,9 @@ void OnLaunchOptionsCreated(const std::string& command
   argv.push_back(command);
   argv.push_back(arg);
   options.current_directory = working_directory;
+#if !BUILDFLAG(IS_BSD)
   options.allow_new_privs = true;
+#endif
   // xdg-open can fall back on mailcap which eventually might plumb through
   // to a command that needs a terminal.  Set the environment variable telling
   // it that we definitely don't have a terminal available and that it should
