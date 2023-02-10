--- v8/src/trap-handler/handler-inside-posix.h.orig	2022-04-21 18:48:31 UTC
+++ v8/src/trap-handler/handler-inside-posix.h
@@ -13,7 +13,7 @@ namespace v8 {
 namespace internal {
 namespace trap_handler {
 
-#if V8_OS_LINUX || V8_OS_FREEBSD
+#if V8_OS_LINUX || V8_OS_FREEBSD || V8_OS_OPENBSD
 constexpr int kOobSignal = SIGSEGV;
 #elif V8_OS_DARWIN
 constexpr int kOobSignal = SIGBUS;
