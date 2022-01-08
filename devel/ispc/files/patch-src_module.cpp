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
@@ -1314,7 +1314,12 @@ bool Module::writeObjectFileOrAssembly(llvm::TargetMachine *targetMachine, llvm::Module *module, OutputType outputType,
     llvm::CodeGenFileType fileType = (outputType == Object) ? llvm::CGFT_ObjectFile : llvm::CGFT_AssemblyFile;
     bool binary = (fileType == llvm::CGFT_ObjectFile);

-    llvm::sys::fs::OpenFlags flags = binary ? llvm::sys::fs::F_None : llvm::sys::fs::F_Text;
+    llvm::sys::fs::OpenFlags flags = binary ?
+#if ISPC_LLVM_VERSION >= ISPC_LLVM_13_0
+                                              llvm::sys::fs::OF_None : llvm::sys::fs::OF_Text;
+#else
+                                              llvm::sys::fs::F_None  : llvm::sys::fs::F_Text;
+#endif

     std::error_code error;

