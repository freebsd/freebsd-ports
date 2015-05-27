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
@@ -76,7 +78,7 @@ std::vector<std::string> DisassembleArm2
 	return lines;
 }
 
-#ifndef ARM
+#if defined(_M_IX86) || defined(_M_X64)
 
 const char *ppsspp_resolver(struct ud*,
 	uint64_t addr,
