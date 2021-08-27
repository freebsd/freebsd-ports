--- llvm/lib/CodeGen/TargetLoweringBase.cpp.orig	2021-08-27 13:06:05 UTC
+++ llvm/lib/CodeGen/TargetLoweringBase.cpp
@@ -1961,7 +1961,8 @@ void TargetLoweringBase::insertSSPDeclarations(Module 
                                   GlobalVariable::ExternalLinkage, nullptr,
                                   "__stack_chk_guard");
     if (TM.getRelocationModel() == Reloc::Static &&
-        !TM.getTargetTriple().isWindowsGNUEnvironment())
+        !TM.getTargetTriple().isWindowsGNUEnvironment() &&
+	!(TM.getTargetTriple().isPPC64() && TM.getTargetTriple().isOSFreeBSD()))
       GV->setDSOLocal(true);
   }
 }
