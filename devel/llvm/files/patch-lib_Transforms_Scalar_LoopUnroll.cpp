
$FreeBSD$

--- lib/Transforms/Scalar/LoopUnroll.cpp.orig
+++ lib/Transforms/Scalar/LoopUnroll.cpp
@@ -365,8 +365,9 @@
       // be updated specially after unrolling all the way.
       if (*BB != LatchBlock)
         for (Value::use_iterator UI = (*BB)->use_begin(), UE = (*BB)->use_end();
-             UI != UE; ++UI) {
+             UI != UE;) {
           Instruction *UseInst = cast<Instruction>(*UI);
+	  ++UI;
           if (isa<PHINode>(UseInst) && !L->contains(UseInst->getParent())) {
             PHINode *phi = cast<PHINode>(UseInst);
             Value *Incoming = phi->getIncomingValueForBlock(*BB);
