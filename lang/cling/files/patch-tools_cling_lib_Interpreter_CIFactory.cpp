--- tools/cling/lib/Interpreter/CIFactory.cpp.orig	2016-12-29 13:54:44 UTC
+++ tools/cling/lib/Interpreter/CIFactory.cpp
@@ -307,8 +307,8 @@ namespace {
           // Note: On FreeBSD it uses getprogpath().
           // Note: Otherwise it uses dladdr().
           //
-          resourcePath
-            = CompilerInvocation::GetResourcesPath("cling",
+          resourcePath = CompilerInvocation::GetResourcesPath(
+                                        "%%LLVM_PREFIX%%/bin/cling",
                                             (void*)intptr_t(GetExecutablePath));
         } else {
           llvm::SmallString<512> tmp(llvmdir);
