--- options.h.orig	2026-01-19 21:20:41.000000000 -0500
+++ options.h	2026-02-25 17:11:16.874661000 -0500
@@ -21,7 +21,11 @@
 #ifndef COMMON_CLANG_OPTIONS_H
 #define COMMON_CLANG_OPTIONS_H
 
+#ifdef USE_PREBUILT_LLVM
+#include "LLVMSPIRVLib/LLVMSPIRVOpts.h"
+#else // USE_PREBUILT_LLVM
 #include "LLVMSPIRVOpts.h"
+#endif // USE_PREBUILT_LLVM
 #include "clang/Basic/OpenCLOptions.h"
 #include "llvm/ADT/ArrayRef.h"
 #include "llvm/ADT/StringRef.h"
