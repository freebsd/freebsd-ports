--- lib/Target/X86/X86InstrSystem.td.orig
+++ lib/Target/X86/X86InstrSystem.td
@@ -573,7 +573,7 @@
 //===----------------------------------------------------------------------===//
 // VIA PadLock crypto instructions
 let Defs = [RAX, RDI], Uses = [RDX, RDI], SchedRW = [WriteSystem] in
-  def XSTORE : I<0xa7, MRM_C0, (outs), (ins), "xstore", []>, TB, REP;
+  def XSTORE : I<0xa7, MRM_C0, (outs), (ins), "xstore", []>, TB;
 
 def : InstAlias<"xstorerng", (XSTORE)>;
 
