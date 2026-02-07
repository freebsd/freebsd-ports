--- swift/lib/IRGen/IRGen.cpp.orig	2024-06-06 04:26:30 UTC
+++ swift/lib/IRGen/IRGen.cpp
@@ -135,6 +135,9 @@ swift::getIRTargetOptions(const IRGenOptions &Opts, AS
   if (Clang->getTargetInfo().getTriple().isOSBinFormatWasm())
     TargetOpts.ThreadModel = llvm::ThreadModel::Single;
 
+  if (Clang->getTargetInfo().getTriple().isOSFreeBSD())
+    TargetOpts.UseInitArray = 1;
+
   if (Opts.EnableGlobalISel) {
     TargetOpts.EnableGlobalISel = true;
     TargetOpts.GlobalISelAbort = GlobalISelAbortMode::DisableWithDiag;
