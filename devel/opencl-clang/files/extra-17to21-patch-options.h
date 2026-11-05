--- options.h.orig	2026-02-25 14:09:49.849351000 -0500
+++ options.h	2026-02-25 14:11:11.623753000 -0500
@@ -27,7 +27,11 @@
 #include "llvm/Option/ArgList.h"
 #include "llvm/Option/Option.h"
 #include "clang/Basic/OpenCLOptions.h"
+#ifdef USE_PREBUILT_LLVM
+#include "LLVMSPIRVLib/LLVMSPIRVOpts.h"
+#else // USE_PREBUILT_LLVM
 #include "LLVMSPIRVOpts.h"
+#endif // USE_PREBUILT_LLVM
 
 #include <list>
 
