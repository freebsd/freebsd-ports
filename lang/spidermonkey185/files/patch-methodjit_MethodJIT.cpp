--- methodjit/MethodJIT.cpp.orig	2011-03-31 19:08:36 UTC
+++ methodjit/MethodJIT.cpp
@@ -189,7 +189,7 @@ JS_STATIC_ASSERT(offsetof(VMFrame, regs.fp) == 0x38);
 JS_STATIC_ASSERT(JSVAL_TAG_MASK == 0xFFFF800000000000LL);
 JS_STATIC_ASSERT(JSVAL_PAYLOAD_MASK == 0x00007FFFFFFFFFFFLL);
 
-asm volatile (
+asm (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerTrampoline) "\n"
 SYMBOL_STRING(JaegerTrampoline) ":"       "\n"
@@ -236,7 +236,7 @@ SYMBOL_STRING(JaegerTrampoline) ":"       "\n"
     "jmp *0(%rsp)"                      "\n"
 );
 
-asm volatile (
+asm (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerTrampolineReturn) "\n"
 SYMBOL_STRING(JaegerTrampolineReturn) ":"       "\n"
@@ -256,7 +256,7 @@ SYMBOL_STRING(JaegerTrampolineReturn) ":"       "\n"
     "ret"                                "\n"
 );
 
-asm volatile (
+asm (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerThrowpoline)  "\n"
 SYMBOL_STRING(JaegerThrowpoline) ":"        "\n"
@@ -281,7 +281,7 @@ SYMBOL_STRING(JaegerThrowpoline) ":"        "\n"
 
 JS_STATIC_ASSERT(offsetof(VMFrame, regs.fp) == 0x38);
 
-asm volatile (
+asm (
 ".text\n"
 ".globl " SYMBOL_STRING(InjectJaegerReturn)   "\n"
 SYMBOL_STRING(InjectJaegerReturn) ":"         "\n"
