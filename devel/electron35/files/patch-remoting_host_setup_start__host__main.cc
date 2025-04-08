--- remoting/host/setup/start_host_main.cc.orig	2025-03-24 20:50:14 UTC
+++ remoting/host/setup/start_host_main.cc
@@ -43,7 +43,7 @@
 #include <unistd.h>
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/setup/daemon_controller_delegate_linux.h"
 #include "remoting/host/setup/start_host_as_root.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -374,7 +374,7 @@ int StartHostMain(int argc, char** argv) {
 }  // namespace
 
 int StartHostMain(int argc, char** argv) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Minimize the amount of code that runs as root on Posix systems.
   if (getuid() == 0) {
     return remoting::StartHostAsRoot(argc, argv);
@@ -399,7 +399,7 @@ int StartHostMain(int argc, char** argv) {
 
   mojo::core::Init();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch("no-start")) {
     // On Linux, registering the host with systemd and starting it is the only
     // reason start_host requires root. The --no-start options skips that final
