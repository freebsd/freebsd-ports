--- src/gallium/drivers/r600/sfn/sfn_optimizer.cpp.orig	2022-12-14 21:06:11 UTC
+++ src/gallium/drivers/r600/sfn/sfn_optimizer.cpp
@@ -354,7 +354,12 @@ CopyPropFwdVisitor::visit(AluInstr *instr)
    auto src = instr->psrc(0);
    auto dest = instr->dest();
 
-   for (auto& i : dest->uses()) {
+   auto ii = dest->uses().begin();
+   auto ie = dest->uses().end();
+
+   while(ii != ie) {
+      auto i = *ii;
+      ++ii;
       /* SSA can always be propagated, registers only in the same block
        * and only if they are assigned in the same block */
       bool can_propagate = dest->is_ssa();
