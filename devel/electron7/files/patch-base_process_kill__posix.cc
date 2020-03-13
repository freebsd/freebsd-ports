--- base/process/kill_posix.cc.orig	2019-12-12 12:38:59 UTC
+++ base/process/kill_posix.cc
@@ -168,7 +168,7 @@ void EnsureProcessTerminated(Process process) {
       0, new BackgroundReaper(std::move(process), TimeDelta::FromSeconds(2)));
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void EnsureProcessGetsReaped(Process process) {
   DCHECK(!process.is_current());
 
@@ -179,7 +179,7 @@ void EnsureProcessGetsReaped(Process process) {
   PlatformThread::CreateNonJoinable(
       0, new BackgroundReaper(std::move(process), TimeDelta()));
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #endif  // !defined(OS_MACOSX)
 #endif  // !defined(OS_NACL_NONSFI)
