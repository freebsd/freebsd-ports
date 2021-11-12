--- llvm/lib/Target/X86/X86InstrSystem.td.orig
+++ llvm/lib/Target/X86/X86InstrSystem.td
@@ -585,7 +585,7 @@
 //===----------------------------------------------------------------------===//
 // VIA PadLock crypto instructions
 let Defs = [RAX, RDI], Uses = [RDX, RDI], SchedRW = [WriteSystem] in
-  def XSTORE : I<0xa7, MRM_C0, (outs), (ins), "xstore", []>, TB, REP;
+  def XSTORE : I<0xa7, MRM_C0, (outs), (ins), "xstore", []>, TB;
 
 def : InstAlias<"xstorerng", (XSTORE)>;
 
