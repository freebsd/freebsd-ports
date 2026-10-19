--- src/base/port.h.orig	2026-10-17 19:46:18 UTC
+++ src/base/port.h
@@ -47,6 +47,7 @@ enum class PlatformType {
   kIos,       // iOS Devices or Simulator
   kWasm,      // WebAssembly
   kChromeos,  // ChromeOS
+  kFreeBSD,   // FreeBSD
 };
 
 // kTargetPlatform is the current build target platform.
@@ -70,9 +71,11 @@ inline constexpr PlatformType kTargetPlatform = Platfo
 #endif                   // !TARGET_OS_IPHONE
 #elif defined(__wasm__)  // __APPLE__
 inline constexpr PlatformType kTargetPlatform = PlatformType::kWasm;
-#else                    // __wasm__
+#elif defined(__FreeBSD__)  // __wasm__
+inline constexpr PlatformType kTargetPlatform = PlatformType::kFreeBSD;
+#else                    // __FreeBSD__
 #error "Unsupported target platform."
-#endif  // !__wasm__
+#endif  // !__FreeBSD__
 
 }  // namespace internal
 
@@ -158,6 +161,11 @@ constexpr bool IsChromeos() {
 // The build target is ChromeOS.
 constexpr bool IsChromeos() {
   return internal::kTargetPlatform == internal::PlatformType::kChromeos;
+}
+
+// The build target is FreeBSD.
+constexpr bool IsFreeBSD() {
+  return internal::kTargetPlatform == internal::PlatformType::kFreeBSD;
 }
 
 }  // namespace port
