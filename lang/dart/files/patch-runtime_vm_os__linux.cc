OS fixes for FreeBSD:
- Use the large-file names from platform/largefile.h (series 0006).
- Thread ids from pthread_getthreadid_np() (series 0007).
- Don't redefine ElfW, which FreeBSD's headers provide (series 0009).
- RSS from sysctl instead of /proc/self/statm (series 0013).
- OS::SafeReadMemory() through a pipe instead of /proc/self/mem
  (series 0014).
FreeBSD-specific, not submitted upstream yet.
--- runtime/vm/os_linux.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/vm/os_linux.cc
@@ -22,6 +22,13 @@
 #include <time.h>          // NOLINT
 #include <unistd.h>        // NOLINT
 
+#if defined(__FreeBSD__)
+#include <pthread_np.h>  // NOLINT
+#include <sys/sysctl.h>  // NOLINT
+#include <sys/user.h>    // NOLINT
+#endif
+
+#include "platform/largefile.h"
 #include "platform/memory_sanitizer.h"
 #include "platform/signal_blocker.h"
 #include "platform/thread_sanitizer.h"
@@ -40,11 +47,14 @@ namespace dart {
 namespace dart {
 
 // Used to choose between Elf32/Elf64 types based on host archotecture bitsize.
+// Some C libraries (e.g. FreeBSD's) already provide it.
+#if !defined(ElfW)
 #if defined(ARCH_IS_64_BIT)
 #define ElfW(Type) Elf64_##Type
 #else
 #define ElfW(Type) Elf32_##Type
 #endif
+#endif  // !defined(ElfW)
 
 // Missing from older versions of <elf.h>.
 #if !defined(EM_RISCV)
@@ -226,7 +236,11 @@ class JitDumpCodeObserver : public CodeObserver {
     ev.size = sizeof(ev) + (name_length + 1) + size;
     ev.time_stamp = OS::GetCurrentMonotonicTicks();
     ev.process_id = getpid();
+#if defined(__FreeBSD__)
+    ev.thread_id = pthread_getthreadid_np();
+#else
     ev.thread_id = syscall(SYS_gettid);
+#endif
     ev.vma = base;
     ev.code_address = base;
     ev.code_size = size;
@@ -541,6 +555,17 @@ uintptr_t OS::CurrentRSS() {
 }
 
 uintptr_t OS::CurrentRSS() {
+#if defined(__FreeBSD__)
+  // FreeBSD does not mount procfs by default; ask the kernel instead.
+  struct kinfo_proc info;
+  size_t size = sizeof(info);
+  int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid()};
+  if (sysctl(mib, sizeof(mib) / sizeof(mib[0]), &info, &size, nullptr, 0) !=
+      0) {
+    return 0;
+  }
+  return static_cast<uintptr_t>(info.ki_rssize) * getpagesize();
+#else
   // The second value in /proc/self/statm is the current RSS in pages.
   // It is not possible to use getrusage() because the interested fields are not
   // implemented by the linux kernel.
@@ -555,6 +580,7 @@ uintptr_t OS::CurrentRSS() {
     return 0;
   }
   return current_rss_pages * getpagesize();
+#endif
 }
 
 bool OS::SafeReadMemory(void* address,
@@ -562,6 +588,38 @@ bool OS::SafeReadMemory(void* address,
                         size_t size_in_bytes,
                         const char** error) {
   ThreadSignalBlocker tsb(SIGPROF);
+#if defined(__FreeBSD__)
+  // There is no /proc/self/mem without procfs. write(2) fails with EFAULT
+  // instead of faulting when the source is not readable, so copy the memory
+  // through a pipe.
+  int fds[2];
+  if (pipe2(fds, O_CLOEXEC) != 0) {
+    *error = strerror(errno);
+    return false;
+  }
+  const size_t kChunkSize = 4 * KB;
+  const uint8_t* source = reinterpret_cast<const uint8_t*>(address);
+  size_t copied = 0;
+  while (copied < size_in_bytes) {
+    const size_t chunk = Utils::Minimum(size_in_bytes - copied, kChunkSize);
+    const ssize_t written = TEMP_FAILURE_RETRY_NO_SIGNAL_BLOCKER(
+        write(fds[1], source + copied, chunk));
+    if (written <= 0) {
+      *error = strerror(errno);
+      break;
+    }
+    const ssize_t read_back = TEMP_FAILURE_RETRY_NO_SIGNAL_BLOCKER(
+        read(fds[0], buffer + copied, written));
+    if (read_back != written) {
+      *error = strerror(errno);
+      break;
+    }
+    copied += read_back;
+  }
+  close(fds[0]);
+  close(fds[1]);
+  return copied == size_in_bytes;
+#else
   int fd = TEMP_FAILURE_RETRY_NO_SIGNAL_BLOCKER(
       open("/proc/self/mem", O_RDONLY | O_CLOEXEC));
   if (fd < 0) {
@@ -575,6 +633,7 @@ bool OS::SafeReadMemory(void* address,
   }
   close(fd);
   return bytes_read == static_cast<ssize_t>(size_in_bytes);
+#endif  // defined(__FreeBSD__)
 }
 
 void OS::Sleep(int64_t millis) {
