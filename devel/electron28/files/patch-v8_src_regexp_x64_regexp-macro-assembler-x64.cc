--- v8/src/regexp/x64/regexp-macro-assembler-x64.cc.orig	2023-08-10 01:51:23 UTC
+++ v8/src/regexp/x64/regexp-macro-assembler-x64.cc
@@ -110,6 +110,7 @@ RegExpMacroAssemblerX64::RegExpMacroAssemblerX64(Isola
       backtrack_label_(),
       exit_label_() {
   DCHECK_EQ(0, registers_to_save % 2);
+  __ CodeEntry();
   __ jmp(&entry_label_);   // We'll write the entry code when we know more.
   __ bind(&start_label_);  // And then continue from here.
 }
@@ -714,6 +715,11 @@ bool RegExpMacroAssemblerX64::CheckSpecialClassRanges(
       // Match any character.
       return true;
   }
+}
+
+void RegExpMacroAssemblerX64::BindJumpTarget(Label* label) {
+  Bind(label);
+  __ CodeEntry();
 }
 
 void RegExpMacroAssemblerX64::Fail() {
