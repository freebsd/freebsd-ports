--- third_party/blink/renderer/platform/wtf/stack_util.cc.orig	2019-03-15 06:38:18 UTC
+++ third_party/blink/renderer/platform/wtf/stack_util.cc
@@ -16,6 +16,11 @@
 extern "C" void* __libc_stack_end;  // NOLINT
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#include <pthread_np.h>
+#endif
+
 namespace WTF {
 
 size_t GetUnderestimatedStackSize() {
