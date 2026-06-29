--- swift/lib/IRGen/IRGen.cpp.orig	2026-04-14 02:40:33 UTC
+++ swift/lib/IRGen/IRGen.cpp
@@ -171,6 +171,9 @@ swift::getIRTargetOptions(const IRGenOptions &Opts, AS
   if (Clang->getTargetInfo().getTriple().isOSBinFormatWasm())
     TargetOpts.ThreadModel = llvm::ThreadModel::Single;
 
+  if (Clang->getTargetInfo().getTriple().isOSFreeBSD())
+    TargetOpts.UseInitArray = 1;
+
   if (Opts.EnableGlobalISel) {
     TargetOpts.EnableGlobalISel = true;
     TargetOpts.GlobalISelAbort = GlobalISelAbortMode::DisableWithDiag;
