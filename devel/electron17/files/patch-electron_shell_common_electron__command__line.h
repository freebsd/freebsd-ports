--- electron/shell/common/electron_command_line.h.orig	2022-05-11 15:32:29 UTC
+++ electron/shell/common/electron_command_line.h
@@ -22,7 +22,7 @@ class ElectronCommandLine {
 
   static void Init(int argc, base::CommandLine::CharType** argv);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux the command line has to be read from base::CommandLine since
   // it is using zygote.
   static void InitializeFromCommandLine();
