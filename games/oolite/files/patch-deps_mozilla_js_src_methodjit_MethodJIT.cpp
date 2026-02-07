--- deps/mozilla/js/src/methodjit/MethodJIT.cpp.orig	2020-09-03 14:46:25 UTC
+++ deps/mozilla/js/src/methodjit/MethodJIT.cpp
@@ -189,7 +189,13 @@ JS_STATIC_ASSERT(offsetof(VMFrame, regs.fp) == 0x38);
 JS_STATIC_ASSERT(JSVAL_TAG_MASK == 0xFFFF800000000000LL);
 JS_STATIC_ASSERT(JSVAL_PAYLOAD_MASK == 0x00007FFFFFFFFFFFLL);
 
-asm volatile (
+#ifndef __clang__
+#define VOLATILE volatile
+#else
+#define VOLATILE
+#endif
+
+asm VOLATILE (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerTrampoline) "\n"
 SYMBOL_STRING(JaegerTrampoline) ":"       "\n"
@@ -236,7 +242,7 @@ SYMBOL_STRING(JaegerTrampoline) ":"       "\n"
     "jmp *0(%rsp)"                      "\n"
 );
 
-asm volatile (
+asm VOLATILE (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerTrampolineReturn) "\n"
 SYMBOL_STRING(JaegerTrampolineReturn) ":"       "\n"
@@ -256,7 +262,7 @@ SYMBOL_STRING(JaegerTrampolineReturn) ":"       "\n"
     "ret"                                "\n"
 );
 
-asm volatile (
+asm VOLATILE (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerThrowpoline)  "\n"
 SYMBOL_STRING(JaegerThrowpoline) ":"        "\n"
@@ -281,7 +287,7 @@ SYMBOL_STRING(JaegerThrowpoline) ":"        "\n"
 
 JS_STATIC_ASSERT(offsetof(VMFrame, regs.fp) == 0x38);
 
-asm volatile (
+asm VOLATILE (
 ".text\n"
 ".globl " SYMBOL_STRING(InjectJaegerReturn)   "\n"
 SYMBOL_STRING(InjectJaegerReturn) ":"         "\n"
@@ -309,7 +315,7 @@ SYMBOL_STRING(InjectJaegerReturn) ":"         "\n"
 JS_STATIC_ASSERT(offsetof(VMFrame, savedEBX) == 0x2c);
 JS_STATIC_ASSERT(offsetof(VMFrame, regs.fp) == 0x1C);
 
-asm volatile (
+asm VOLATILE (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerTrampoline) "\n"
 SYMBOL_STRING(JaegerTrampoline) ":"       "\n"
@@ -339,7 +345,7 @@ SYMBOL_STRING(JaegerTrampoline) ":"       "\n"
     "jmp *16(%ebp)"                      "\n"
 );
 
-asm volatile (
+asm VOLATILE (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerTrampolineReturn) "\n"
 SYMBOL_STRING(JaegerTrampolineReturn) ":" "\n"
@@ -357,7 +363,7 @@ SYMBOL_STRING(JaegerTrampolineReturn) ":" "\n"
     "ret"                                "\n"
 );
 
-asm volatile (
+asm VOLATILE (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerThrowpoline)  "\n"
 SYMBOL_STRING(JaegerThrowpoline) ":"        "\n"
@@ -388,7 +394,7 @@ SYMBOL_STRING(JaegerThrowpoline) ":"        "\n"
 
 JS_STATIC_ASSERT(offsetof(VMFrame, regs.fp) == 0x1C);
 
-asm volatile (
+asm VOLATILE (
 ".text\n"
 ".globl " SYMBOL_STRING(InjectJaegerReturn)   "\n"
 SYMBOL_STRING(InjectJaegerReturn) ":"         "\n"
@@ -423,7 +429,7 @@ JS_STATIC_ASSERT(JSReturnReg_Type == JSC::ARMRegisters
 #define FUNCTION_HEADER_EXTRA
 #endif
 
-asm volatile (
+asm VOLATILE (
 ".text\n"
 FUNCTION_HEADER_EXTRA
 ".globl " SYMBOL_STRING(InjectJaegerReturn) "\n"
@@ -436,7 +442,7 @@ SYMBOL_STRING(InjectJaegerReturn) ":"       "\n"
     "bx  lr"                                "\n"
 );
 
-asm volatile (
+asm VOLATILE (
 ".text\n"
 FUNCTION_HEADER_EXTRA
 ".globl " SYMBOL_STRING(JaegerTrampoline)   "\n"
@@ -495,7 +501,7 @@ SYMBOL_STRING(JaegerTrampoline) ":"         "\n"
 "   bx     r4"                                  "\n"
 );
 
-asm volatile (
+asm VOLATILE (
 ".text\n"
 FUNCTION_HEADER_EXTRA
 ".globl " SYMBOL_STRING(JaegerTrampolineReturn)   "\n"
@@ -515,7 +521,7 @@ SYMBOL_STRING(JaegerTrampolineReturn) ":"         "\n"
 "   pop     {r4-r11,pc}"                    "\n"
 );
 
-asm volatile (
+asm VOLATILE (
 ".text\n"
 FUNCTION_HEADER_EXTRA
 ".globl " SYMBOL_STRING(JaegerThrowpoline)  "\n"
@@ -540,7 +546,7 @@ SYMBOL_STRING(JaegerThrowpoline) ":"        "\n"
 "   pop     {r4-r11,pc}"                    "\n"
 );
 
-asm volatile (
+asm VOLATILE (
 ".text\n"
 FUNCTION_HEADER_EXTRA
 ".globl " SYMBOL_STRING(JaegerStubVeneer)   "\n"
