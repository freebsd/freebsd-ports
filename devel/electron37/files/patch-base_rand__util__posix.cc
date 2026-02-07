--- base/rand_util_posix.cc.orig	2025-04-22 20:15:27 UTC
+++ base/rand_util_posix.cc
@@ -29,7 +29,7 @@
 #include "base/time/time.h"
 #include "build/build_config.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_NACL)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 #include "third_party/lss/linux_syscall_support.h"
 #elif BUILDFLAG(IS_MAC)
 // TODO(crbug.com/40641285): Waiting for this header to appear in the iOS SDK.
@@ -45,6 +45,7 @@ namespace {
 
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_AIX)
 // AIX has no 64-bit support for O_CLOEXEC.
 static constexpr int kOpenFlags = O_RDONLY;
@@ -69,10 +70,11 @@ class URandomFd {
  private:
   const int fd_;
 };
+#endif
 
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
      BUILDFLAG(IS_ANDROID)) &&                        \
-    !BUILDFLAG(IS_NACL)
+    !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 
 bool KernelSupportsGetRandom() {
   return base::SysInfo::KernelVersionNumber::Current() >=
@@ -129,6 +131,7 @@ void RandBytesInternal(span<uint8_t> output, bool avoi
 namespace {
 
 void RandBytesInternal(span<uint8_t> output, bool avoid_allocation) {
+#if !BUILDFLAG(IS_BSD)
 #if !BUILDFLAG(IS_NACL)
   // The BoringSSL experiment takes priority over everything else.
   if (!avoid_allocation && internal::UseBoringSSLForRandBytes()) {
@@ -163,6 +166,9 @@ void RandBytesInternal(span<uint8_t> output, bool avoi
   const int urandom_fd = GetUrandomFD();
   const bool success = ReadFromFD(urandom_fd, as_writable_chars(output));
   CHECK(success);
+#else
+  arc4random_buf(output.data(), output.size());
+#endif
 }
 
 }  // namespace
@@ -182,9 +188,11 @@ void RandBytes(span<uint8_t> output) {
   RandBytesInternal(output, /*avoid_allocation=*/false);
 }
 
+#if !BUILDFLAG(IS_BSD)
 int GetUrandomFD() {
   static NoDestructor<URandomFd> urandom_fd;
   return urandom_fd->fd();
 }
+#endif
 
 }  // namespace base
