--- interpreter/cling/lib/Interpreter/Interpreter.cpp.orig	2024-04-01 14:37:20 UTC
+++ interpreter/cling/lib/Interpreter/Interpreter.cpp
@@ -876,8 +876,10 @@ namespace cling {
                                     /*AllowExtraSearch*/ true))
       return loadModule(M, complain);
 
+#ifndef __FreeBSD__ // See 'FreeBSD port maintainer note' in core/clingutils/CMakeLists.txt
    if (complain)
      llvm::errs() << "Module " << moduleName << " not found.\n";
+#endif
 
 
    return false;
