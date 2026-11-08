--- Core/MIPS/fake/FakeJit.h.orig	2026-05-16 12:31:51 UTC
+++ Core/MIPS/fake/FakeJit.h
@@ -48,6 +48,7 @@
 	void DoJit(u32 em_address, JitBlock *b);
 
 	const u8 *GetCrashHandler() const override { return nullptr; }
+	const u8 *GetCodeBase() const override { return nullptr; }
 	bool CodeInRange(const u8 *ptr) const override { return IsInSpace(ptr); }
 	bool DescribeCodePtr(const u8 *ptr, std::string &name) override;
 
