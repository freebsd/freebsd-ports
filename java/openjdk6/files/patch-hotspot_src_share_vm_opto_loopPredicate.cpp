--- hotspot/src/share/vm/opto/loopPredicate.cpp.orig	2017-05-30 15:21:46 UTC
+++ hotspot/src/share/vm/opto/loopPredicate.cpp
@@ -831,7 +831,7 @@ bool PhaseIdealLoop::loop_predication_impl(IdealLoopTr
       Node*          idx    = cmp->in(1);
       assert(!invar.is_invariant(idx), "index is variant");
       Node* rng = cmp->in(2);
-      assert(rng->Opcode() == Op_LoadRange || _igvn.type(rng)->is_int() >= 0, "must be");
+      assert(rng->Opcode() == Op_LoadRange, "must be");
       assert(invar.is_invariant(rng), "range must be invariant");
       int scale    = 1;
       Node* offset = zero;
