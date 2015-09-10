--- Core/MIPS/fake/FakeJit.cpp.orig	2015-02-26 20:05:06 UTC
+++ Core/MIPS/fake/FakeJit.cpp
@@ -138,7 +138,7 @@ void FakeJit::RunLoopUntil(u64 globaltic
 	((void (*)())enterCode)();
 }
 
-const u8 *FakeJit::DoFakeJit(u32 em_address, FakeJitBlock *b)
+const u8 *FakeJit::DoJit(u32 em_address, JitBlock *b)
 {
 	return b->normalEntry;
 }
