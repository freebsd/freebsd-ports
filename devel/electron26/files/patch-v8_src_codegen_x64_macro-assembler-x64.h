--- v8/src/codegen/x64/macro-assembler-x64.h.orig	2023-08-10 01:51:22 UTC
+++ v8/src/codegen/x64/macro-assembler-x64.h
@@ -625,11 +625,14 @@ class V8_EXPORT_PRIVATE MacroAssembler
 
   // Define a function entrypoint. This doesn't emit any code for this
   // architecture, as control-flow integrity is not supported for it.
-  void CodeEntry() {}
+  void CodeEntry();
   // Define an exception handler.
-  void ExceptionHandler() {}
+  void ExceptionHandler() { CodeEntry(); }
   // Define an exception handler and bind a label.
-  void BindExceptionHandler(Label* label) { bind(label); }
+  void BindExceptionHandler(Label* label) {
+    bind(label);
+    CodeEntry();
+  }
 
   // ---------------------------------------------------------------------------
   // Pointer compression support
