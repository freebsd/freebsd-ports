--- disas/libvixl/a64/disasm-a64.cc.orig	2015-11-03 20:01:31 UTC
+++ disas/libvixl/a64/disasm-a64.cc
@@ -1362,7 +1362,7 @@ void Disassembler::AppendPCRelativeOffse
                                                   int64_t offset) {
   USE(instr);
   char sign = (offset < 0) ? '-' : '+';
-  AppendToOutput("#%c0x%" PRIx64, sign, std::abs(offset));
+  AppendToOutput("#%c0x%" PRIx64, sign, offset < 0 ? -offset : offset);
 }
 
 
