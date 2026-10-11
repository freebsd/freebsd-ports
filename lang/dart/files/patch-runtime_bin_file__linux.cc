File fixes:
- Retry sendfile64() on EINTR (series 0000). Backport of upstream
  765cab96b7b (dart-lang/sdk#64473); drop once a release has it.
- Use the large-file names from platform/largefile.h (series 0006).
- Copy files with copy_file_range(), since FreeBSD's sendfile() only
  writes to sockets (series 0011).
- Stat the descriptor itself for /dev/fd/N, which is a character device
  on FreeBSD (series 0020).
Except for the backport: FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/file_linux.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/file_linux.cc
@@ -10,16 +10,21 @@
 #include <errno.h>         // NOLINT
 #include <fcntl.h>         // NOLINT
 #include <libgen.h>        // NOLINT
+#include <stdio.h>         // NOLINT
 #include <sys/mman.h>      // NOLINT
-#include <sys/sendfile.h>  // NOLINT
 #include <sys/stat.h>      // NOLINT
 #include <sys/types.h>     // NOLINT
 #include <unistd.h>        // NOLINT
 #include <utime.h>         // NOLINT
 
+#if !defined(__FreeBSD__)
+#include <sys/sendfile.h>  // NOLINT
+#endif
+
 #include "bin/builtin.h"
 #include "bin/fdutils.h"
 #include "bin/namespace.h"
+#include "platform/largefile.h"
 #include "platform/signal_blocker.h"
 #include "platform/syslog.h"
 #include "platform/utils.h"
@@ -359,6 +364,35 @@ bool File::CreatePipe(Namespace* namespc, File** readP
   return true;
 }
 
+#if defined(__FreeBSD__)
+// On FreeBSD, /dev/fd/N (from devfs or fdescfs) is a character device, while
+// on Linux and macOS following it reaches the open file itself, e.g. a pipe.
+// Stat the descriptor for such paths to get the same result.
+static bool StatDevFd(const char* path, struct stat64* st, int* result) {
+  int fd;
+  char trailing;
+  if (sscanf(path, "/dev/fd/%d%c", &fd, &trailing) != 1 || fd < 0) {
+    return false;
+  }
+  *result = TEMP_FAILURE_RETRY(fstat64(fd, st));
+  return true;
+}
+#endif  // defined(__FreeBSD__)
+
+// Like fstatat64(dirfd, path, st, 0), following /dev/fd/N on FreeBSD.
+static int StatFollowingLinks(const char* name,
+                              int dirfd,
+                              const char* path,
+                              struct stat64* st) {
+#if defined(__FreeBSD__)
+  int result;
+  if (StatDevFd(name, st, &result)) {
+    return result;
+  }
+#endif
+  return TEMP_FAILURE_RETRY(fstatat64(dirfd, path, st, 0));
+}
+
 File::Type File::GetType(Namespace* namespc,
                          const char* name,
                          bool follow_links) {
@@ -367,7 +401,7 @@ File::Type File::GetType(Namespace* namespc,
   int stat_success;
   if (follow_links) {
     stat_success =
-        TEMP_FAILURE_RETRY(fstatat64(ns.fd(), ns.path(), &entry_info, 0));
+        StatFollowingLinks(name, ns.fd(), ns.path(), &entry_info);
   } else {
     stat_success = TEMP_FAILURE_RETRY(
         fstatat64(ns.fd(), ns.path(), &entry_info, AT_SYMLINK_NOFOLLOW));
@@ -469,7 +503,7 @@ bool File::Copy(Namespace* namespc,
   }
   NamespaceScope oldns(namespc, old_path);
   struct stat64 st;
-  if (TEMP_FAILURE_RETRY(fstatat64(oldns.fd(), oldns.path(), &st, 0)) != 0) {
+  if (StatFollowingLinks(old_path, oldns.fd(), oldns.path(), &st) != 0) {
     return false;
   }
   const int old_fd = TEMP_FAILURE_RETRY(
@@ -489,7 +523,17 @@ bool File::Copy(Namespace* namespc,
   intptr_t result = 1;
   while (result > 0) {
     // Loop to ensure we copy everything, and not only up to 2GB.
-    result = NO_RETRY_EXPECTED(sendfile64(new_fd, old_fd, &offset, kMaxUint32));
+#if defined(__FreeBSD__)
+    // FreeBSD's sendfile() only writes to sockets.
+    off_t in_offset = offset;
+    result = TEMP_FAILURE_RETRY(
+        copy_file_range(old_fd, &in_offset, new_fd, nullptr, kMaxUint32, 0));
+    offset = in_offset;
+#else
+    // sendfile64 can fail with EINTR if no data was written yet.
+    result =
+        TEMP_FAILURE_RETRY(sendfile64(new_fd, old_fd, &offset, kMaxUint32));
+#endif
   }
   // From sendfile man pages:
   //   Applications may wish to fall back to read(2)/write(2) in the case
@@ -559,7 +603,7 @@ void File::Stat(Namespace* namespc, const char* name, 
 void File::Stat(Namespace* namespc, const char* name, int64_t* data) {
   NamespaceScope ns(namespc, name);
   struct stat64 st;
-  if (TEMP_FAILURE_RETRY(fstatat64(ns.fd(), ns.path(), &st, 0)) == 0) {
+  if (StatFollowingLinks(name, ns.fd(), ns.path(), &st) == 0) {
     if (S_ISREG(st.st_mode)) {
       data[kType] = kIsFile;
     } else if (S_ISDIR(st.st_mode)) {
