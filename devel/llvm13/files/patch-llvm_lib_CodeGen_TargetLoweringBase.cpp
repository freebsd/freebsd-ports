diff --git a/contrib/llvm-project/llvm/lib/CodeGen/TargetLoweringBase.cpp b/contrib/llvm-project/llvm/lib/CodeGen/TargetLoweringBase.cpp
--- llvm/lib/CodeGen/TargetLoweringBase.cpp
+++ llvm/lib/CodeGen/TargetLoweringBase.cpp
@@ -1961,7 +1961,8 @@
                                   GlobalVariable::ExternalLinkage, nullptr,
                                   "__stack_chk_guard");
     if (TM.getRelocationModel() == Reloc::Static &&
-        !TM.getTargetTriple().isWindowsGNUEnvironment())
+        !TM.getTargetTriple().isWindowsGNUEnvironment() &&
+	!(TM.getTargetTriple().isPPC64() && TM.getTargetTriple().isOSFreeBSD()))
       GV->setDSOLocal(true);
   }
 }

