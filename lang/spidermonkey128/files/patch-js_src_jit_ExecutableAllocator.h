Index: js/src/jit/ExecutableAllocator.h
--- js/src/jit/ExecutableAllocator.h.orig	2022-03-30 19:25:41 UTC
+++ js/src/jit/ExecutableAllocator.h
@@ -39,6 +39,10 @@
 #include "js/TypeDecls.h"
 #include "js/Vector.h"
 
+#if defined(__OpenBSD__) && defined(__mips64__)
+#include <mips64/sysarch.h>
+#endif
+
 namespace JS {
 struct CodeSizes;
 }  // namespace JS
