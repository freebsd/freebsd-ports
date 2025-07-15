--- electron/shell/common/electron_command_line.cc.orig	2025-04-04 05:26:44 UTC
+++ electron/shell/common/electron_command_line.cc
@@ -35,7 +35,7 @@ std::vector<std::string> ElectronCommandLine::AsUtf8()
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void ElectronCommandLine::InitializeFromCommandLine() {
   argv_ = base::CommandLine::ForCurrentProcess()->argv();
