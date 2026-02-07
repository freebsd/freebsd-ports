--- runtime/power.S.orig	2024-02-05 15:40:20 UTC
+++ runtime/power.S
@@ -13,7 +13,7 @@
 /*                                                                        */
 /**************************************************************************/
 
-#if defined(MODEL_ppc64le)
+#if _CALL_ELF == 2
         .abiversion 2
 #endif
 
@@ -27,7 +27,7 @@
 #define DOMAIN_STATE_PTR 30
 #define ALLOC_PTR 31
 
-#if defined(MODEL_ppc64) || defined(MODEL_ppc64le)
+#if _CALL_ELF == 1 || _CALL_ELF == 2
 #define EITHER(a,b) b
 #else
 #define EITHER(a,b) a
@@ -52,7 +52,7 @@
 #define CALLBACK_LINK_SIZE 16
 #define CALLBACK_LINK_OFFSET 0
 #endif
-#if defined(MODEL_ppc64)
+#if _CALL_ELF == 1
 #define RESERVED_STACK 48
 #define PARAM_SAVE_AREA (8*8)
 #define LR_SAVE 16
@@ -64,7 +64,7 @@
 #define CALLBACK_LINK_SIZE 32
 #define CALLBACK_LINK_OFFSET 48
 #endif
-#if defined(MODEL_ppc64le)
+#if _CALL_ELF == 2
 #define RESERVED_STACK 32
 #define PARAM_SAVE_AREA 0
 #define LR_SAVE 16
@@ -92,7 +92,7 @@
 
 #endif
 
-#if defined(MODEL_ppc64)
+#if _CALL_ELF == 1
 #define FUNCTION(name) \
   .section ".opd","aw"; \
   .align 3; \
@@ -108,7 +108,7 @@
 
 #endif
 
-#if defined(MODEL_ppc64le)
+#if _CALL_ELF == 2
 #define FUNCTION(name) \
   .section ".text"; \
   .globl name; \
@@ -133,7 +133,7 @@
         addi    reg, reg, glob@l
 #endif
 
-#if defined(MODEL_ppc64) || defined(MODEL_ppc64le)
+#if _CALL_ELF == 1 || _CALL_ELF == 2
 
 #define LSYMB(glob) .L##glob
 
@@ -150,7 +150,7 @@
 
 #define Caml_state(var) 8*domain_field_caml_##var(DOMAIN_STATE_PTR)
 
-#if defined(MODEL_ppc64)
+#if _CALL_ELF == 1
         .section ".opd","aw"
 #else
         .section ".text"
@@ -237,7 +237,7 @@ FUNCTION(caml_call_gc)
         stfdu   31, 8(11)
     /* Call the GC */
         bl      caml_garbage_collection
-#if defined(MODEL_ppc64) || defined(MODEL_ppc64le)
+#if _CALL_ELF == 1 || _CALL_ELF == 2
         nop
 #endif
     /* Reload new allocation pointer */
@@ -329,14 +329,14 @@ FUNCTION(caml_c_call)
 #if defined(MODEL_ppc)
         mtctr   C_CALL_FUN
         bctrl
-#elif defined(MODEL_ppc64)
+#elif _CALL_ELF == 1
         ld      0, 0(C_CALL_FUN)
         mr      C_CALL_TOC, 2   /* save current TOC in a callee-save register */
         mtctr   0
         ld      2, 8(C_CALL_FUN)
         bctrl
         mr      2, C_CALL_TOC   /* restore current TOC */
-#elif defined(MODEL_ppc64le)
+#elif _CALL_ELF == 2
         mtctr   C_CALL_FUN
         mr      12, C_CALL_FUN
         mr      C_CALL_TOC, 2   /* save current TOC in a callee-save register */
@@ -378,7 +378,7 @@ FUNCTION(caml_raise_exn)
         addi    1, 1, -(PARAM_SAVE_AREA + RESERVED_STACK)
                                 /* reserve stack space for C call */
         bl      caml_stash_backtrace
-#if defined(MODEL_ppc64) || defined(MODEL_ppc64le)
+#if _CALL_ELF == 1 || _CALL_ELF == 2
         nop
 #endif
         mr      3, 27           /* restore exn bucket */
@@ -414,7 +414,7 @@ FUNCTION(caml_raise_exception)
         addi    1, 1, -(PARAM_SAVE_AREA + RESERVED_STACK)
                                          /* reserve stack space for C call */
         bl      caml_stash_backtrace
-#if defined(MODEL_ppc64) || defined(MODEL_ppc64le)
+#if _CALL_ELF == 1 || _CALL_ELF == 2
         nop
 #endif
         mr      3, 27           /* restore exn bucket */
@@ -507,14 +507,14 @@ FUNCTION(caml_start_program)
 #if defined(MODEL_ppc)
         mtctr   12
 .L105:  bctrl
-#elif defined(MODEL_ppc64)
+#elif _CALL_ELF == 1
         ld      0, 0(12)
         mtctr   0
         std     2, TOC_SAVE(1)
         ld      2, 8(12)
 .L105:  bctrl
         ld      2, TOC_SAVE(1)
-#elif defined(MODEL_ppc64le)
+#elif _CALL_ELF == 2
         mtctr   12
         std     2, TOC_SAVE(1)
 .L105:  bctrl
@@ -633,7 +633,7 @@ ENDFUNCTION(caml_callback3_asm)
         b       .L102
 ENDFUNCTION(caml_callback3_asm)
 
-#if defined(MODEL_ppc64)
+#if _CALL_ELF == 1
         .section ".opd","aw"
 #else
         .section ".text"
@@ -655,7 +655,7 @@ caml_system__frametable:
 
 /* TOC entries */
 
-#if defined(MODEL_ppc64) || defined(MODEL_ppc64le)
+#if _CALL_ELF == 1 || _CALL_ELF == 2
 
         .section ".toc", "aw"
 
