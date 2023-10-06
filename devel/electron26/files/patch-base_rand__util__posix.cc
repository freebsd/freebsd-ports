--- base/rand_util_posix.cc.orig	2022-11-30 08:12:58 UTC
+++ base/rand_util_posix.cc
@@ -22,7 +22,7 @@
 #include "base/time/time.h"
 #include "build/build_config.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_NACL)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 #include "third_party/lss/linux_syscall_support.h"
 #elif BUILDFLAG(IS_MAC)
 // TODO(crbug.com/995996): Waiting for this header to appear in the iOS SDK.
@@ -46,6 +46,7 @@ static constexpr int kOpenFlags = O_RDONLY;
 static constexpr int kOpenFlags = O_RDONLY | O_CLOEXEC;
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 // We keep the file descriptor for /dev/urandom around so we don't need to
 // reopen it (which is expensive), and since we may not even be able to reopen
 // it if we are later put in a sandbox. This class wraps the file descriptor so
@@ -63,10 +64,11 @@ class URandomFd {
  private:
   const int fd_;
 };
+#endif
 
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
      BUILDFLAG(IS_ANDROID)) &&                        \
-    !BUILDFLAG(IS_NACL)
+    !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 // TODO(pasko): Unify reading kernel version numbers in:
 // mojo/core/channel_linux.cc
 // chrome/browser/android/seccomp_support_detector.cc
@@ -176,6 +178,7 @@ bool UseBoringSSLForRandBytes() {
 namespace {
 
 void RandBytes(void* output, size_t output_length, bool avoid_allocation) {
+#if !BUILDFLAG(IS_BSD)
 #if !BUILDFLAG(IS_NACL)
   // The BoringSSL experiment takes priority over everything else.
   if (!avoid_allocation && internal::UseBoringSSLForRandBytes()) {
@@ -214,6 +217,9 @@ void RandBytes(void* output, size_t output_length, boo
   const bool success =
       ReadFromFD(urandom_fd, static_cast<char*>(output), output_length);
   CHECK(success);
+#else
+  arc4random_buf(static_cast<char*>(output), output_length);
+#endif
 }
 
 }  // namespace
@@ -233,9 +239,11 @@ void RandBytes(void* output, size_t output_length) {
   RandBytes(output, output_length, /*avoid_allocation=*/false);
 }
 
+#if !BUILDFLAG(IS_BSD)
 int GetUrandomFD() {
   static NoDestructor<URandomFd> urandom_fd;
   return urandom_fd->fd();
 }
+#endif
 
 }  // namespace base
