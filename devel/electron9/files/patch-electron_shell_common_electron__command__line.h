--- electron/shell/common/electron_command_line.h.orig	2020-05-18 21:17:08 UTC
+++ electron/shell/common/electron_command_line.h
@@ -21,7 +21,7 @@ class ElectronCommandLine {
 
   static void Init(int argc, base::CommandLine::CharType** argv);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux the command line has to be read from base::CommandLine since
   // it is using zygote.
   static void InitializeFromCommandLine();
