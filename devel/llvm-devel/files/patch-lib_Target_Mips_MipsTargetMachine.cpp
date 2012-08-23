
$FreeBSD$

--- lib/Target/Mips/MipsTargetMachine.cpp.orig
+++ lib/Target/Mips/MipsTargetMachine.cpp
@@ -54,6 +54,11 @@
     FrameLowering(MipsFrameLowering::create(*this, Subtarget)),
     TLInfo(*this), TSInfo(*this), JITInfo(),
     ELFWriterInfo(false, isLittle) {
+
+  // The system as doesn't understand CFI on FreeBSD
+#if defined(__FreeBSD__)
+  setMCUseCFI(false);
+#endif
 }
 
 void MipsebTargetMachine::anchor() { }
