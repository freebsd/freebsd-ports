--- tools/cling/lib/Interpreter/CIFactory.cpp.orig	2018-08-14 07:05:28 UTC
+++ tools/cling/lib/Interpreter/CIFactory.cpp
@@ -187,7 +187,7 @@ namespace {
       // Note: Otherwise it uses dladdr().
       //
       return CompilerInvocation::GetResourcesPath(
-          "cling", (void*)intptr_t(GetExecutablePath));
+          "%%LLVM_PREFIX%%/bin/cling", (void*)intptr_t(GetExecutablePath));
     } else {
       std::string resourcePath;
       llvm::SmallString<512> tmp(llvmdir);
