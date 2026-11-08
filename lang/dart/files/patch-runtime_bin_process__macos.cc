Move SignalMap() unchanged into bin/process_signal_map.h (series 0016)
so the Linux code can use it on FreeBSD (series 0017). The header is
files/process_signal_map.h. No change on macOS.
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/process_macos.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/process_macos.cc
@@ -24,6 +24,7 @@
 #include "bin/fdutils.h"
 #include "bin/lockers.h"
 #include "bin/namespace.h"
+#include "bin/process_signal_map.h"
 #include "bin/thread.h"
 #include "platform/syslog.h"
 
@@ -918,70 +919,6 @@ int Process::Exec(Namespace* namespc,
   Utils::StrError(errno, errmsg, errmsg_len);
   return -1;
 #endif
-}
-
-static int SignalMap(intptr_t id) {
-  switch (static_cast<ProcessSignals>(id)) {
-    case kSighup:
-      return SIGHUP;
-    case kSigint:
-      return SIGINT;
-    case kSigquit:
-      return SIGQUIT;
-    case kSigill:
-      return SIGILL;
-    case kSigtrap:
-      return SIGTRAP;
-    case kSigabrt:
-      return SIGABRT;
-    case kSigbus:
-      return SIGBUS;
-    case kSigfpe:
-      return SIGFPE;
-    case kSigkill:
-      return SIGKILL;
-    case kSigusr1:
-      return SIGUSR1;
-    case kSigsegv:
-      return SIGSEGV;
-    case kSigusr2:
-      return SIGUSR2;
-    case kSigpipe:
-      return SIGPIPE;
-    case kSigalrm:
-      return SIGALRM;
-    case kSigterm:
-      return SIGTERM;
-    case kSigchld:
-      return SIGCHLD;
-    case kSigcont:
-      return SIGCONT;
-    case kSigstop:
-      return SIGSTOP;
-    case kSigtstp:
-      return SIGTSTP;
-    case kSigttin:
-      return SIGTTIN;
-    case kSigttou:
-      return SIGTTOU;
-    case kSigurg:
-      return SIGURG;
-    case kSigxcpu:
-      return SIGXCPU;
-    case kSigxfsz:
-      return SIGXFSZ;
-    case kSigvtalrm:
-      return SIGVTALRM;
-    case kSigprof:
-      return SIGPROF;
-    case kSigwinch:
-      return SIGWINCH;
-    case kSigpoll:
-      return -1;
-    case kSigsys:
-      return SIGSYS;
-  }
-  return -1;
 }
 
 bool Process::Kill(intptr_t id, int signal) {
