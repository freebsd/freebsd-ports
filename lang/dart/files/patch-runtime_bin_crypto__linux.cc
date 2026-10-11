FreeBSD has no __NR_getrandom; call getrandom(2) directly (series 0009).
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/crypto_linux.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/crypto_linux.cc
@@ -9,6 +9,10 @@
 #include <fcntl.h>
 #include <sys/syscall.h>
 
+#if defined(__FreeBSD__)
+#include <sys/random.h>
+#endif
+
 #include "bin/crypto.h"
 #include "bin/fdutils.h"
 #include "platform/memory_sanitizer.h"
@@ -45,8 +49,12 @@ bool Crypto::GetRandomBytes(intptr_t count, uint8_t* b
   do {
     ssize_t res;
     do {
+#if defined(__FreeBSD__)
+      res = getrandom(buffer + bytes_read, count - bytes_read, /*flags=*/0);
+#else
       res = syscall(__NR_getrandom, buffer + bytes_read, count - bytes_read,
                     /*flags=*/0);
+#endif
     } while (res == -1 && errno == EINTR);
     if (res == -1) {
       if (errno == ENOSYS) {
