--- options_compile.cpp.orig	2026-02-25 14:12:14.857353000 -0500
+++ options_compile.cpp	2026-02-25 14:13:19.590114000 -0500
@@ -72,7 +72,11 @@
 #define _STRINGIFY(X) #X
 #define STRINGIFY(X) _STRINGIFY(X)
 #define EXT(X) ExtensionNamesMap[STRINGIFY(X)] = SPIRV::ExtensionID::X;
+#ifdef USE_PREBUILT_LLVM
+#include "LLVMSPIRVLib/LLVMSPIRVExtensions.inc"
+#else // USE_PREBUILT_LLVM
 #include "LLVMSPIRVExtensions.inc"
+#endif // USE_PREBUILT_LLVM
 #undef EXT
 #undef STRINGIFY
 #undef _STRINGIFY
