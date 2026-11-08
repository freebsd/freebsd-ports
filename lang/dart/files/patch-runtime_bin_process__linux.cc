Process fixes for FreeBSD:
- Use the large-file names from platform/largefile.h (series 0006).
- Get open-file paths from fcntl(F_KINFO) and the RSS from sysctl,
  since procfs isn't mounted by default (series 0013).
- Translate dart:io ProcessSignal numbers (Linux numbering) with
  SignalMap() from process_signal_map.h, as macOS does (series 0017).
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/process_linux.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/process_linux.cc
@@ -17,13 +17,22 @@
 #include <sys/wait.h>      // NOLINT
 #include <unistd.h>        // NOLINT
 
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>  // NOLINT
+#include <sys/user.h>    // NOLINT
+#endif
+
 #include "bin/dartutils.h"
 #include "bin/directory.h"
 #include "bin/fdutils.h"
 #include "bin/file.h"
 #include "bin/lockers.h"
 #include "bin/reference_counting.h"
+#if defined(__FreeBSD__)
+#include "bin/process_signal_map.h"
+#endif
 #include "bin/thread.h"
+#include "platform/largefile.h"
 #include "platform/syslog.h"
 
 #include "platform/signal_blocker.h"
@@ -269,6 +278,17 @@ static bool PathInNamespace(char* realpath,
   if (fd == -1) {
     return false;
   }
+#if defined(__FreeBSD__)
+  // No /proc/self/fd on FreeBSD; F_KINFO reports the path of an open file.
+  struct kinfo_file info = {};
+  info.kf_structsize = sizeof(info);
+  if (fcntl(fd, F_KINFO, &info) != 0) {
+    FDUtils::SaveErrorAndClose(fd);
+    return false;
+  }
+  strncpy(realpath, info.kf_path, realpath_size);
+  realpath[realpath_size - 1] = '\0';
+#else
   char procpath[PATH_MAX];
   snprintf(procpath, PATH_MAX, "/proc/self/fd/%d", fd);
   const intptr_t length =
@@ -278,6 +298,7 @@ static bool PathInNamespace(char* realpath,
     return false;
   }
   realpath[length] = '\0';
+#endif
   FDUtils::SaveErrorAndClose(fd);
   return true;
 }
@@ -954,8 +975,18 @@ int Process::Exec(Namespace* namespc,
   return -1;
 }
 
+// ProcessSignal ids are Linux signal numbers; FreeBSD numbers some signals
+// differently (e.g. SIGUSR1 is 30, while 10 is SIGBUS).
+static int OsSignal(intptr_t signal) {
+#if defined(__FreeBSD__)
+  return SignalMap(signal);
+#else
+  return signal;
+#endif
+}
+
 bool Process::Kill(intptr_t id, int signal) {
-  return (TEMP_FAILURE_RETRY(kill(id, signal)) != -1);
+  return (TEMP_FAILURE_RETRY(kill(id, OsSignal(signal))) != -1);
 }
 
 void Process::TerminateExitCodeHandler() {
@@ -966,13 +997,25 @@ intptr_t Process::CurrentProcessId() {
   return static_cast<intptr_t>(getpid());
 }
 
+#if !defined(__FreeBSD__)
 static void SaveErrorAndClose(FILE* file) {
   int actual_errno = errno;
   fclose(file);
   errno = actual_errno;
 }
+#endif
 
 int64_t Process::CurrentRSS() {
+#if defined(__FreeBSD__)
+  struct kinfo_proc info;
+  size_t size = sizeof(info);
+  int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid()};
+  if (sysctl(mib, sizeof(mib) / sizeof(mib[0]), &info, &size, nullptr, 0) !=
+      0) {
+    return -1;
+  }
+  return static_cast<int64_t>(info.ki_rssize) * getpagesize();
+#else
   // The second value in /proc/self/statm is the current RSS in pages.
   // It is not possible to use getrusage() because the interested fields are not
   // implemented by the linux kernel.
@@ -988,6 +1031,7 @@ int64_t Process::CurrentRSS() {
   }
   fclose(statm);
   return current_rss_pages * getpagesize();
+#endif
 }
 
 int64_t Process::MaxRSS() {
@@ -1025,6 +1069,10 @@ intptr_t Process::SetSignalHandler(intptr_t signal) {
 }
 
 intptr_t Process::SetSignalHandler(intptr_t signal) {
+  signal = OsSignal(signal);
+  if (signal == -1) {
+    return -1;
+  }
   bool found = false;
   for (int i = 0; i < kSignalsCount; i++) {
     if (kSignals[i] == signal) {
@@ -1076,6 +1124,10 @@ void Process::ClearSignalHandler(intptr_t signal, Dart
 }
 
 void Process::ClearSignalHandler(intptr_t signal, Dart_Port port) {
+  signal = OsSignal(signal);
+  if (signal == -1) {
+    return;
+  }
   ThreadSignalBlocker blocker(kSignalsCount, kSignals);
   MutexLocker lock(signal_mutex);
   SignalInfo* handler = signal_handlers;
