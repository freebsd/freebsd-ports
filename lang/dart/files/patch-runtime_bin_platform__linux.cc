Platform fixes for FreeBSD:
- No prctl(PR_SET_NAME): name the thread with pthread_setname_np();
  the BUS_MCEERR_* codes are Linux-only; declare environ, which
  <unistd.h> doesn't on FreeBSD (series 0009).
- Executable path from sysctl(KERN_PROC_PATHNAME) instead of
  /proc/self/exe (series 0013).
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/platform_linux.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/platform_linux.cc
@@ -10,7 +10,6 @@
 #include <errno.h>
 #include <signal.h>
 #include <string.h>
-#include <sys/prctl.h>
 #include <sys/resource.h>
 #if defined(DART_HOST_OS_ANDROID)
 #include <sys/system_properties.h>
@@ -18,9 +17,21 @@
 #include <sys/utsname.h>
 #include <unistd.h>
 
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#include <sys/sysctl.h>
+#else
+#include <sys/prctl.h>
+#endif
+
 #include "bin/console.h"
+#include "bin/dartutils.h"
 #include "bin/file.h"
 
+#if defined(__FreeBSD__)
+extern char** environ;
+#endif
+
 namespace dart {
 namespace bin {
 
@@ -45,8 +56,10 @@ static const char* strcode(int si_signo, int si_code) 
   CASE(SIGBUS, BUS_ADRALN);
   CASE(SIGBUS, BUS_ADRERR);
   CASE(SIGBUS, BUS_OBJERR);
+#if defined(BUS_MCEERR_AR)  // Linux-specific machine check codes.
   CASE(SIGBUS, BUS_MCEERR_AR);
   CASE(SIGBUS, BUS_MCEERR_AO);
+#endif
   CASE(SIGTRAP, TRAP_BRKPT);
   CASE(SIGTRAP, TRAP_TRACE);
 #undef CASE
@@ -186,16 +199,51 @@ const char* Platform::GetExecutableName() {
   return executable_name_;
 }
 
+#if defined(__FreeBSD__)
+// FreeBSD does not mount procfs by default, so there is no /proc/self/exe.
+// Ask the kernel for the executable's path instead. Like File::ReadLinkInto,
+// returns the length including the terminating NUL, or -1 on failure.
+static intptr_t GetExecutablePathInto(char* result, size_t result_size) {
+  int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+  size_t length = result_size;
+  if (sysctl(mib, sizeof(mib) / sizeof(mib[0]), result, &length, nullptr, 0) !=
+      0) {
+    return -1;
+  }
+  return length;
+}
+#endif  // defined(__FreeBSD__)
+
 const char* Platform::ResolveExecutablePath() {
+#if defined(__FreeBSD__)
+  char path[PATH_MAX + 1];
+  const intptr_t length = GetExecutablePathInto(path, sizeof(path));
+  if (length <= 0) {
+    return nullptr;
+  }
+  char* result = DartUtils::ScopedCString(length);
+  memmove(result, path, length);
+  return result;
+#else
   return File::ReadLink("/proc/self/exe");
+#endif
 }
 
 intptr_t Platform::ResolveExecutablePathInto(char* result, size_t result_size) {
+#if defined(__FreeBSD__)
+  return GetExecutablePathInto(result, result_size);
+#else
   return File::ReadLinkInto("/proc/self/exe", result, result_size);
+#endif
 }
 
 void Platform::SetProcessName(const char* name) {
+#if defined(__FreeBSD__)
+  // Like PR_SET_NAME, this names the calling thread.
+  pthread_setname_np(pthread_self(), name);
+#else
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name), 0, 0, 0);  // NOLINT
+#endif
 }
 
 void Platform::Exit(int exit_code) {
