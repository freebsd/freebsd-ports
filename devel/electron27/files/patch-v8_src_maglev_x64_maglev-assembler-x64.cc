--- v8/src/maglev/x64/maglev-assembler-x64.cc.orig	2023-10-19 20:00:42 UTC
+++ v8/src/maglev/x64/maglev-assembler-x64.cc
@@ -433,10 +433,12 @@ void MaglevAssembler::OSRPrologue(Graph* graph) {
 void MaglevAssembler::Prologue(Graph* graph) {
   DCHECK(!graph->is_osr());
 
+  CodeEntry();
+
   BailoutIfDeoptimized(rbx);
 
   if (graph->has_recursive_calls()) {
-    bind(code_gen_state()->entry_label());
+    BindJumpTarget(code_gen_state()->entry_label());
   }
 
   // Tiering support.
