--- llvm/lib/CodeGen/TargetLoweringBase.cpp.orig	2021-09-24 16:18:10 UTC
+++ llvm/lib/CodeGen/TargetLoweringBase.cpp
@@ -1980,8 +1980,11 @@ void TargetLoweringBase::insertSSPDeclarations(Module 
     auto *GV = new GlobalVariable(M, Type::getInt8PtrTy(M.getContext()), false,
                                   GlobalVariable::ExternalLinkage, nullptr,
                                   "__stack_chk_guard");
+
+    // FreeBSD has "__stack_chk_guard" defined externally on libc.so
     if (TM.getRelocationModel() == Reloc::Static &&
-        !TM.getTargetTriple().isWindowsGNUEnvironment())
+        !TM.getTargetTriple().isWindowsGNUEnvironment() &&
+        !TM.getTargetTriple().isOSFreeBSD())
       GV->setDSOLocal(true);
   }
 }
