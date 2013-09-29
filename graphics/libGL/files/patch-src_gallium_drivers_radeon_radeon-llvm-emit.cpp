--- src/gallium/drivers/radeon/radeon_llvm_emit.cpp.orig	2013-08-19 21:23:06.000000000 +0200
+++ src/gallium/drivers/radeon/radeon_llvm_emit.cpp	2013-08-19 21:30:58.000000000 +0200
@@ -25,13 +25,13 @@
  */
 #include "radeon_llvm_emit.h"
 
-#include <llvm/LLVMContext.h>
-#include <llvm/Module.h>
+#include <llvm/IR/LLVMContext.h>
+#include <llvm/IR/Module.h>
 #include <llvm/PassManager.h>
 #include <llvm/ADT/Triple.h>
 #include <llvm/Support/FormattedStream.h>
 #include <llvm/Support/Host.h>
-#include <llvm/Support/IRReader.h>
+#include <llvm/IRReader/IRReader.h>
 #include <llvm/Support/SourceMgr.h>
 #include <llvm/Support/TargetRegistry.h>
 #include <llvm/Support/TargetSelect.h>
@@ -39,7 +39,7 @@
 #include <llvm/Target/TargetMachine.h>
 #include <llvm/Transforms/Scalar.h>
 #include <llvm-c/Target.h>
-#include <llvm/DataLayout.h>
+#include <llvm/IR/DataLayout.h>
 
 #include <iostream>
 #include <stdlib.h>
