--- src/module.cpp.orig	2021-07-15 23:04:31 UTC
+++ src/module.cpp
@@ -102,7 +102,7 @@
 #define OCLOC_LIBRARY_NAME "ocloc64.dll"
 #elif defined(_WIN32)
 #define OCLOC_LIBRARY_NAME "ocloc32.dll"
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #define OCLOC_LIBRARY_NAME "libocloc.so"
 #else
 #error "Unexpected platform"
@@ -1149,7 +1149,7 @@ bool Module::translateToSPIRV(llvm::Module *module, st
         llvm::cl::desc("Allow DWARF operations not listed in the OpenCL.DebugInfo.100 "
                        "specification (experimental, may produce incompatible SPIR-V "
                        "module)"));
-#if ISPC_LLVM_VERSION < ISPC_LLVM_12_0
+#if ISPC_LLVM_VERSION >= ISPC_LLVM_13_0
     Opts.setSPIRVAllowUnknownIntrinsics({"llvm.genx"});
 #else
     llvm::cl::opt<bool> SPIRVAllowUnknownIntrinsics(
