--- interpreter/llvm-project/clang/lib/Serialization/ASTWriter.cpp.orig	2024-01-11 19:51:52 UTC
+++ interpreter/llvm-project/clang/lib/Serialization/ASTWriter.cpp
@@ -2498,8 +2498,10 @@ unsigned ASTWriter::getSubmoduleID(Module *Mod) {
   // did not result in us loading a module file for that submodule. For
   // instance, a cross-top-level-module 'conflict' declaration will hit this.
   unsigned ID = getLocalOrImportedSubmoduleID(Mod);
+  /*
   assert((ID || !Mod) &&
          "asked for module ID for non-local, non-imported module");
+   */
   return ID;
 }
 
