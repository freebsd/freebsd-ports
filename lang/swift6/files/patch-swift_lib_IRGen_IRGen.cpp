--- swift/lib/IRGen/IRGen.cpp.orig	2026-09-13 22:35:30 UTC
+++ swift/lib/IRGen/IRGen.cpp
@@ -180,6 +180,9 @@ swift::getIRTargetOptions(const IRGenOptions &Opts, AS
   if (Clang->getTargetInfo().getTriple().isOSBinFormatWasm())
     TargetOpts.ThreadModel = llvm::ThreadModel::Single;
 
+  if (Clang->getTargetInfo().getTriple().isOSFreeBSD())
+    TargetOpts.UseInitArray = 1;
+
   if (Opts.EnableGlobalISel) {
     TargetOpts.EnableGlobalISel = true;
     TargetOpts.GlobalISelAbort = GlobalISelAbortMode::DisableWithDiag;
