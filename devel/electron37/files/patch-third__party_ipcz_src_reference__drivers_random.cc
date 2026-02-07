--- third_party/ipcz/src/reference_drivers/random.cc.orig	2025-04-22 20:15:27 UTC
+++ third_party/ipcz/src/reference_drivers/random.cc
@@ -55,7 +55,7 @@ decltype(&ProcessPrng) GetProcessPrng() {
 }
 #endif
 
-#if defined(OS_POSIX) && !BUILDFLAG(IS_MAC)
+#if defined(OS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 void RandomBytesFromDevUrandom(absl::Span<uint8_t> destination) {
   static int urandom_fd = [] {
     for (;;) {
@@ -99,7 +99,7 @@ void RandomBytes(absl::Span<uint8_t> destination) {
       return;
     }
   }
-#elif BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   const bool ok = getentropy(destination.data(), destination.size()) == 0;
   ABSL_ASSERT(ok);
 #elif BUILDFLAG(IS_IOS)
