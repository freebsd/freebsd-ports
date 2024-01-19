--- v8/src/execution/isolate.cc.orig	2024-01-04 06:17:44 UTC
+++ v8/src/execution/isolate.cc
@@ -147,6 +147,10 @@
 #include "src/execution/simulator-base.h"
 #endif
 
+#if defined(V8_OS_OPENBSD)
+#include <sys/mman.h>
+#endif
+
 extern "C" const uint8_t v8_Default_embedded_blob_code_[];
 extern "C" uint32_t v8_Default_embedded_blob_code_size_;
 extern "C" const uint8_t v8_Default_embedded_blob_data_[];
@@ -3950,6 +3954,11 @@ void Isolate::InitializeDefaultEmbeddedBlob() {
   uint32_t code_size = DefaultEmbeddedBlobCodeSize();
   const uint8_t* data = DefaultEmbeddedBlobData();
   uint32_t data_size = DefaultEmbeddedBlobDataSize();
+
+#if defined(V8_OS_OPENBSD) && !defined(V8_TARGET_ARCH_IA32)
+  mprotect(reinterpret_cast<void *>(const_cast<uint8_t *>(code)),
+          code_size, PROT_READ | PROT_EXEC);
+#endif
 
   if (StickyEmbeddedBlobCode() != nullptr) {
     base::MutexGuard guard(current_embedded_blob_refcount_mutex_.Pointer());
