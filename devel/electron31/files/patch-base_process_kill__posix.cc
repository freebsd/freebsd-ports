--- base/process/kill_posix.cc.orig	2023-03-30 00:33:38 UTC
+++ base/process/kill_posix.cc
@@ -157,7 +157,7 @@ void EnsureProcessTerminated(Process process) {
       0, new BackgroundReaper(std::move(process), Seconds(2)));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void EnsureProcessGetsReaped(Process process) {
   DCHECK(!process.is_current());
 
