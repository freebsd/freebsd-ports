--- tools/clang/include/clang/Basic/DiagnosticSemaKinds.td.orig
+++ tools/clang/include/clang/Basic/DiagnosticSemaKinds.td
@@ -3180,6 +3180,9 @@
 
 def note_ovl_candidate_inherited_constructor : Note<
     "constructor from base class %0 inherited here">;
+def note_ovl_candidate_inherited_constructor_slice : Note<
+    "candidate %select{constructor|template}0 ignored: "
+    "inherited constructor cannot be used to %select{copy|move}1 object">;
 def note_ovl_candidate_illegal_constructor : Note<
     "candidate %select{constructor|template}0 ignored: "
     "instantiation %select{takes|would take}0 its own class type by value">;
