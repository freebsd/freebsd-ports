--- v8/src/maglev/x64/maglev-assembler-x64.cc.orig	2023-08-10 01:51:23 UTC
+++ v8/src/maglev/x64/maglev-assembler-x64.cc
@@ -553,13 +553,15 @@ void MaglevAssembler::TryChangeFloat64ToIndex(Register
 }
 
 void MaglevAssembler::Prologue(Graph* graph) {
+  CodeEntry();
+
   if (!graph->is_osr()) {
     BailoutIfDeoptimized(rbx);
   }
 
   CHECK_IMPLIES(graph->is_osr(), !graph->has_recursive_calls());
   if (graph->has_recursive_calls()) {
-    bind(code_gen_state()->entry_label());
+    BindJumpTarget(code_gen_state()->entry_label());
   }
 
   // Tiering support.
