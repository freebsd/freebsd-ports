--- v8/src/regexp/x64/regexp-macro-assembler-x64.h.orig	2023-08-10 01:51:23 UTC
+++ v8/src/regexp/x64/regexp-macro-assembler-x64.h
@@ -59,6 +59,9 @@ class V8_EXPORT_PRIVATE RegExpMacroAssemblerX64
   void CheckPosition(int cp_offset, Label* on_outside_input) override;
   bool CheckSpecialClassRanges(StandardCharacterSet type,
                                Label* on_no_match) override;
+
+  void BindJumpTarget(Label* label) override;
+
   void Fail() override;
   Handle<HeapObject> GetCode(Handle<String> source) override;
   void GoTo(Label* label) override;
