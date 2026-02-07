--- testsuite/tools/asmgen_power.S.orig	2022-12-20 12:26:44 UTC
+++ testsuite/tools/asmgen_power.S
@@ -10,7 +10,7 @@
 /*                                                                   */
 /*********************************************************************/
 
-#if defined(MODEL_ppc64) || defined(MODEL_ppc64le)
+#if _CALL_ELF == 1 || _CALL_ELF == 2
 #define EITHER(a,b) b
 #else
 #define EITHER(a,b) a
@@ -26,11 +26,11 @@
 #define RESERVED_STACK 16
 #define LR_SAVE_AREA 4
 #endif
-#if defined(MODEL_ppc64)
+#if _CALL_ELF == 1
 #define RESERVED_STACK 48
 #define LR_SAVE_AREA 16
 #endif
-#if defined(MODEL_ppc64le)
+#if _CALL_ELF == 2
 #define RESERVED_STACK 32
 #define LR_SAVE_AREA 16
 #endif
@@ -46,7 +46,7 @@
   name:
 #endif
 
-#if defined(MODEL_ppc64)
+#if _CALL_ELF == 1
 #define FUNCTION(name) \
   .section ".opd","aw"; \
   .align 3; \
@@ -58,7 +58,7 @@
   .L.name:
 #endif
 
-#if defined(MODEL_ppc64le)
+#if _CALL_ELF == 2
 #define FUNCTION(name) \
   .section ".text"; \
   .globl name; \
@@ -118,11 +118,11 @@ FUNCTION(call_gen_code)
     /* Get function pointer in CTR */
 #if defined(MODEL_ppc)
         mtctr   3
-#elif defined(MODEL_ppc64)
+#elif _CALL_ELF == 1
         ld      0, 0(3)
         mtctr   0
         ld      2, 8(3)
-#elif defined(MODEL_ppc64le)
+#elif _CALL_ELF == 2
         mtctr   3
         mr      12, 3
 #else
@@ -184,11 +184,11 @@ FUNCTION(caml_c_call)
     /* Jump to C function (address in r28) */
 #if defined(MODEL_ppc)
         mtctr   28
-#elif defined(MODEL_ppc64)
+#elif _CALL_ELF == 1
         ld      0, 0(28)
         mtctr   0
         ld      2, 8(28)
-#elif defined(MODEL_ppc64le)
+#elif _CALL_ELF == 2
         mtctr   28
         mr      12, 28
 #else
