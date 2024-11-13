--- electron/shell/common/electron_command_line.h.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/common/electron_command_line.h
@@ -22,7 +22,7 @@ class ElectronCommandLine {
 
   static void Init(int argc, base::CommandLine::CharType** argv);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux the command line has to be read from base::CommandLine since
   // it is using zygote.
   static void InitializeFromCommandLine();
