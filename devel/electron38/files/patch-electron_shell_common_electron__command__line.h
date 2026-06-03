--- electron/shell/common/electron_command_line.h.orig	2025-04-04 05:26:44 UTC
+++ electron/shell/common/electron_command_line.h
@@ -24,7 +24,7 @@ class ElectronCommandLine {
 
   static void Init(int argc, base::CommandLine::CharType const* const* argv);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux the command line has to be read from base::CommandLine since
   // it is using zygote.
   static void InitializeFromCommandLine();
