--- Core/MIPS/JitCommon/JitCommon.cpp.orig	2015-02-26 20:05:06 UTC
+++ Core/MIPS/JitCommon/JitCommon.cpp
@@ -27,8 +27,10 @@
 namespace MIPSComp {
 #if defined(ARM)
 	ArmJit *jit;
-#else
+#elif defined(_M_IX86) || defined(_M_X64) || defined(MIPS)
 	Jit *jit;
+#else
+	FakeJit *jit;
 #endif
 	void JitAt() {
 		jit->Compile(currentMIPS->pc);
@@ -95,10 +97,12 @@ const char *ppsspp_resolver(struct ud*,
 		*offset = addr - (uint64_t)MIPSComp::jit->GetBasePtr();
 		return "jitcode";
 	}
+#if defined(_M_IX86) || defined(_M_X64) || defined(MIPS)
 	if (MIPSComp::jit->Asm().IsInSpace((u8 *)(intptr_t)addr)) {
 		*offset = addr - (uint64_t)MIPSComp::jit->Asm().GetBasePtr();
 		return "dispatcher";
 	}
+#endif
 
 	return NULL;
 }
