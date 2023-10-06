--- third_party/ipcz/src/reference_drivers/random.cc.orig	2023-05-25 00:42:44 UTC
+++ third_party/ipcz/src/reference_drivers/random.cc
@@ -15,7 +15,7 @@
 #include <limits>
 #elif BUILDFLAG(IS_FUCHSIA)
 #include <zircon/syscalls.h>
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include <asm/unistd.h>
 #include <sys/syscall.h>
 #include <unistd.h>
@@ -78,7 +78,7 @@ void RandomBytes(absl::Span<uint8_t> destination) {
   ABSL_ASSERT(ok);
 #elif BUILDFLAG(IS_FUCHSIA)
   zx_cprng_draw(destination.data(), destination.size());
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   while (!destination.empty()) {
     ssize_t result =
         syscall(__NR_getrandom, destination.data(), destination.size(), 0);
