--- UI/DevScreens.cpp.orig	2015-02-26 20:05:06 UTC
+++ UI/DevScreens.cpp
@@ -612,12 +612,14 @@ void JitCompareScreen::UpdateDisasm() {
 
 #if defined(ARM)
 	std::vector<std::string> targetDis = DisassembleArm2(block->normalEntry, block->codeSize);
-#else
+#elif defined(_M_IX86) || defined(_M_X64)
 	std::vector<std::string> targetDis = DisassembleX86(block->normalEntry, block->codeSize);
 #endif
+#if defined(ARM) || defined(_M_IX86) || defined(_M_X64)
 	for (size_t i = 0; i < targetDis.size(); i++) {
 		rightDisasm_->Add(new TextView(targetDis[i]));
 	}
+#endif
 
 	int numMips = leftDisasm_->GetNumSubviews();
 	int numHost = rightDisasm_->GetNumSubviews();
