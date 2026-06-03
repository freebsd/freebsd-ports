--- electron/shell/browser/relauncher_linux.cc.orig	2025-07-02 10:12:01 UTC
+++ electron/shell/browser/relauncher_linux.cc
@@ -6,8 +6,10 @@
 
 #include <fcntl.h>
 #include <signal.h>
+#if !defined(__FreeBSD__)
 #include <sys/prctl.h>
 #include <sys/signalfd.h>
+#endif
 
 #include "base/files/scoped_file.h"
 #include "base/logging.h"
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
@@ -47,6 +53,7 @@ void RelauncherSynchronizeWithParent() {
 
   // Wait for the parent to exit
   parentWaiter.Wait();
+#endif
 }
 
 int LaunchProgram(const StringVector& relauncher_args,
