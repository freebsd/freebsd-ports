Build the kqueue event handler on FreeBSD too (series 0012). It only
relies on kqueue, so FreeBSD uses it instead of the epoll one, with two
differences: descriptors are created close-on-exec with pipe2() and
kqueue1(), and non-tty character devices such as /dev/null are treated
as closed, as macOS's kevent() does (FreeBSD accepts them but never
reports them ready, which hung reads from /dev/null). No change on macOS.
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/eventhandler_macos.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/eventhandler_macos.cc
@@ -3,7 +3,7 @@
 // BSD-style license that can be found in the LICENSE file.
 
 #include "platform/globals.h"
-#if defined(DART_HOST_OS_MACOS)
+#if defined(DART_HOST_OS_MACOS) || defined(__FreeBSD__)
 
 #include "bin/eventhandler.h"
 #include "bin/eventhandler_macos.h"
@@ -14,6 +14,7 @@
 #include <stdio.h>      // NOLINT
 #include <string.h>     // NOLINT
 #include <sys/event.h>  // NOLINT
+#include <sys/stat.h>   // NOLINT
 #include <unistd.h>     // NOLINT
 
 #include "bin/dartutils.h"
@@ -78,6 +79,17 @@ static void AddToKqueue(intptr_t kqueue_fd_, Descripto
   }
   ASSERT(changes > 0);
   ASSERT(changes <= kMaxChanges);
+#if defined(__FreeBSD__)
+  // FreeBSD accepts filters on character devices such as /dev/null, but
+  // never reports them as ready, so reading from them would hang. macOS
+  // rejects them instead; handle character devices other than terminals the
+  // same way.
+  struct stat st;
+  if (fstat(di->fd(), &st) == 0 && S_ISCHR(st.st_mode) && !isatty(di->fd())) {
+    di->NotifyAllDartPorts(1 << kCloseEvent);
+    return;
+  }
+#endif
   int status = NO_RETRY_EXPECTED(
       kevent(kqueue_fd_, events, changes, nullptr, 0, nullptr));
   if (status == -1) {
@@ -96,28 +108,42 @@ EventHandlerImplementation::EventHandlerImplementation
 EventHandlerImplementation::EventHandlerImplementation()
     : socket_map_(&SimpleHashMap::SamePointerValue, 16) {
   intptr_t result;
+#if defined(__FreeBSD__)
+  // FreeBSD uses the Linux FDUtils, which expect descriptors to be created
+  // with O_CLOEXEC rather than having it set afterwards.
+  result = NO_RETRY_EXPECTED(pipe2(interrupt_fds_, O_CLOEXEC));
+#else
   result = NO_RETRY_EXPECTED(pipe(interrupt_fds_));
+#endif
   if (result != 0) {
     FATAL("Pipe creation failed");
   }
   if (!FDUtils::SetNonBlocking(interrupt_fds_[0])) {
     FATAL("Failed to set pipe fd non-blocking\n");
   }
+#if !defined(__FreeBSD__)
   if (!FDUtils::SetCloseOnExec(interrupt_fds_[0])) {
     FATAL("Failed to set pipe fd close on exec\n");
   }
   if (!FDUtils::SetCloseOnExec(interrupt_fds_[1])) {
     FATAL("Failed to set pipe fd close on exec\n");
   }
+#endif
   shutdown_ = false;
 
+#if defined(__FreeBSD__)
+  kqueue_fd_ = NO_RETRY_EXPECTED(kqueue1(O_CLOEXEC));
+#else
   kqueue_fd_ = NO_RETRY_EXPECTED(kqueue());
+#endif
   if (kqueue_fd_ == -1) {
     FATAL("Failed creating kqueue");
   }
+#if !defined(__FreeBSD__)
   if (!FDUtils::SetCloseOnExec(kqueue_fd_)) {
     FATAL("Failed to set kqueue fd close on exec\n");
   }
+#endif
   // Register the interrupt_fd with the kqueue.
   struct kevent event;
   EV_SET(&event, interrupt_fds_[0], EVFILT_READ, EV_ADD, 0, 0, nullptr);
@@ -501,4 +527,4 @@ uint32_t EventHandlerImplementation::GetHashmapHashFro
 }  // namespace bin
 }  // namespace dart
 
-#endif  // defined(DART_HOST_OS_MACOS)
+#endif  // defined(DART_HOST_OS_MACOS) || defined(__FreeBSD__)
