--- electron/shell/common/electron_command_line.cc.orig	2025-10-27 17:58:27 UTC
+++ electron/shell/common/electron_command_line.cc
@@ -39,7 +39,7 @@ std::vector<std::string> ElectronCommandLine::AsUtf8()
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void ElectronCommandLine::InitializeFromCommandLine() {
   argv() = base::CommandLine::ForCurrentProcess()->argv();
