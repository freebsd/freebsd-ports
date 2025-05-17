--- base/debug/stack_trace_posix.cc.orig	2025-03-24 20:50:14 UTC
+++ base/debug/stack_trace_posix.cc
@@ -51,7 +51,7 @@
 // execinfo.h and backtrace(3) are really only present in glibc and in macOS
 // libc.
 #if BUILDFLAG(IS_APPLE) || \
-    (defined(__GLIBC__) && !defined(__UCLIBC__) && !defined(__AIX))
+    (defined(__GLIBC__) && !defined(__UCLIBC__) && !defined(__AIX) && !BUILDFLAG(IS_BSD))
 #define HAVE_BACKTRACE
 #include <execinfo.h>
 #endif
@@ -69,8 +69,10 @@
 #include <AvailabilityMacros.h>
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+#if !BUILDFLAG(IS_BSD)
 #include <sys/prctl.h>
+#endif
 
 #include "base/debug/proc_maps_linux.h"
 #endif
@@ -329,7 +331,7 @@ void PrintToStderr(const char* output) {
   std::ignore = HANDLE_EINTR(write(STDERR_FILENO, output, strlen(output)));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void AlarmSignalHandler(int signal, siginfo_t* info, void* void_context) {
   // We have seen rare cases on AMD linux where the default signal handler
   // either does not run or a thread (Probably an AMD driver thread) prevents
@@ -346,7 +348,11 @@ void AlarmSignalHandler(int signal, siginfo_t* info, v
       "Warning: Default signal handler failed to terminate process.\n");
   PrintToStderr("Calling exit_group() directly to prevent timeout.\n");
   // See: https://man7.org/linux/man-pages/man2/exit_group.2.html
+#if BUILDFLAG(IS_BSD) 
+  _exit(EXIT_FAILURE);
+#else
   syscall(SYS_exit_group, EXIT_FAILURE);
+#endif
 }
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -552,7 +558,7 @@ void StackDumpSignalHandler(int signal, siginfo_t* inf
     _exit(EXIT_FAILURE);
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Set an alarm to trigger in case the default handler does not terminate
   // the process. See 'AlarmSignalHandler' for more details.
   struct sigaction action;
@@ -577,6 +583,7 @@ void StackDumpSignalHandler(int signal, siginfo_t* inf
   // signals that do not re-raise autonomously), such as signals delivered via
   // kill() and asynchronous hardware faults such as SEGV_MTEAERR, which would
   // otherwise be lost when re-raising the signal via raise().
+#if !BUILDFLAG(IS_BSD)
   long retval = syscall(SYS_rt_tgsigqueueinfo, getpid(), syscall(SYS_gettid),
                         info->si_signo, info);
   if (retval == 0) {
@@ -591,6 +598,7 @@ void StackDumpSignalHandler(int signal, siginfo_t* inf
   if (errno != EPERM) {
     _exit(EXIT_FAILURE);
   }
+#endif
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) ||
         // BUILDFLAG(IS_CHROMEOS)
 
@@ -783,6 +791,7 @@ class SandboxSymbolizeHelper {
     return -1;
   }
 
+#if !BUILDFLAG(IS_BSD)
   // This class is copied from
   // third_party/crashpad/crashpad/util/linux/scoped_pr_set_dumpable.h.
   // It aims at ensuring the process is dumpable before opening /proc/self/mem.
@@ -875,11 +884,15 @@ class SandboxSymbolizeHelper {
       r.base = cur_base;
     }
   }
+#endif
 
   // Parses /proc/self/maps in order to compile a list of all object file names
   // for the modules that are loaded in the current process.
   // Returns true on success.
   bool CacheMemoryRegions() {
+#if BUILDFLAG(IS_BSD)
+    return false;
+#else
     // Reads /proc/self/maps.
     std::string contents;
     if (!ReadProcMaps(&contents)) {
@@ -897,6 +910,7 @@ class SandboxSymbolizeHelper {
 
     is_initialized_ = true;
     return true;
+#endif
   }
 
   // Opens all object files and caches their file descriptors.
