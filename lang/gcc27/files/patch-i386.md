--- config/i386/i386.md.orig	Mon Aug 21 10:27:58 1995
+++ config/i386/i386.md	Mon Mar 20 13:29:12 2000
@@ -5312,10 +5312,17 @@
      coprocessor registers as containing a possible return value,
      simply pretend the untyped call returns a complex long double
      value.  */
+#if 1
+  /* this may be part of (set (reg: ..) (call_insn ...)), and we can't
+     directly set a fp register from the call.  so we revert to the
+     old behavior - jlemon@netcom.com (Jonathan Lemon) */
+  emit_call_insn (gen_call (operands[0], const0_rtx, NULL, const0_rtx));
+#else
   emit_call_insn (TARGET_80387
                   ? gen_call_value (gen_rtx (REG, XCmode, FIRST_FLOAT_REG),
 		                  operands[0], const0_rtx)
                   : gen_call (operands[0], const0_rtx));
+#endif
 
   for (i = 0; i < XVECLEN (operands[2], 0); i++)
     {
