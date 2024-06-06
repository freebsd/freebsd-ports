--- interpreter/cling/lib/Interpreter/Interpreter.cpp.orig	2024-05-30 18:23:48 UTC
+++ interpreter/cling/lib/Interpreter/Interpreter.cpp
@@ -889,8 +889,10 @@ namespace cling {
                                     /*AllowExtraSearch*/ true))
       return loadModule(M, complain);
 
+#ifndef __FreeBSD__ // See 'FreeBSD port maintainer note' in core/clingutils/CMakeLists.txt
    if (complain)
      llvm::errs() << "Module " << moduleName << " not found.\n";
+#endif
 
 
    return false;
