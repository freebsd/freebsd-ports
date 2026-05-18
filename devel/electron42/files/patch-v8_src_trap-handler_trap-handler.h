--- v8/src/trap-handler/trap-handler.h.orig	2025-06-30 07:04:30 UTC
+++ v8/src/trap-handler/trap-handler.h
@@ -18,7 +18,7 @@ namespace v8::internal::trap_handler {
 // X64 on Linux, Windows, MacOS, FreeBSD.
 #if V8_HOST_ARCH_X64 && V8_TARGET_ARCH_X64 &&                        \
     ((V8_OS_LINUX && !V8_OS_ANDROID) || V8_OS_WIN || V8_OS_DARWIN || \
-     V8_OS_FREEBSD)
+     V8_OS_FREEBSD || V8_OS_OPENBSD)
 #define V8_TRAP_HANDLER_SUPPORTED true
 // Arm64 native on Linux, Windows, MacOS.
 #elif V8_TARGET_ARCH_ARM64 && V8_HOST_ARCH_ARM64 && \
