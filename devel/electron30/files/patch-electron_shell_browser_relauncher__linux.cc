--- electron/shell/browser/relauncher_linux.cc.orig	2023-01-24 16:58:16 UTC
+++ electron/shell/browser/relauncher_linux.cc
@@ -6,8 +6,10 @@
 
 #include <fcntl.h>
 #include <signal.h>
+#if !defined(__FreeBSD__)
 #include <sys/prctl.h>
 #include <sys/signalfd.h>
+#endif
 
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
@@ -24,6 +26,10 @@ void RelauncherSynchronizeWithParent() {
   base::ScopedFD relauncher_sync_fd(kRelauncherSyncFD);
   static const auto signum = SIGUSR2;
 
+#if defined(__FreeBSD__)
+  PLOG(ERROR) << "signalfd & prctl";
+  fprintf(stderr, "Not Implemented signalfd & prctl in atom/browser/relauncher_linux.cc");
+#else
   // send signum to current process when parent process ends.
   if (HANDLE_EINTR(prctl(PR_SET_PDEATHSIG, signum)) != 0) {
     PLOG(ERROR) << "prctl";
@@ -48,6 +54,7 @@ void RelauncherSynchronizeWithParent() {
 
   // Wait for the parent to exit
   parentWaiter.Wait();
+#endif
 }
 
 int LaunchProgram(const StringVector& relauncher_args,
