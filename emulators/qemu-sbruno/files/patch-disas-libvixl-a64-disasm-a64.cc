--- a/disas/libvixl/a64/disasm-a64.cc
+++ b/disas/libvixl/a64/disasm-a64.cc
@@ -1337,7 +1337,8 @@ void Disassembler::AppendPCRelativeOffse
                                                   int64_t offset) {
   USE(instr);
   char sign = (offset < 0) ? '-' : '+';
-  AppendToOutput("#%c0x%" PRIx64, sign, std::abs(offset));
+  // AppendToOutput("#%c0x%" PRIx64, sign, std::abs(offset));
+  AppendToOutput("#%c0x%" PRIx64, sign, offset < 0 ? -offset : offset);
 }
 
 
