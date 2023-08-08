--- runtime/power.S.orig	2019-08-05 17:32:44 UTC
+++ runtime/power.S
@@ -13,11 +13,11 @@
 /*                                                                        */
 /**************************************************************************/
 
-#if defined(MODEL_ppc64le)
+#if _CALL_ELF == 2
         .abiversion 2
 #endif
 
-#if defined(MODEL_ppc64) || defined(MODEL_ppc64le)
+#if _CALL_ELF == 1 || _CALL_ELF == 2
 #define EITHER(a,b) b
 #else
 #define EITHER(a,b) a
@@ -42,7 +42,7 @@
 #define CALLBACK_LINK_SIZE 16
 #define CALLBACK_LINK_OFFSET 0
 #endif
-#if defined(MODEL_ppc64)
+#if _CALL_ELF == 1
 #define RESERVED_STACK 48
 #define PARAM_SAVE_AREA (8*8)
 #define LR_SAVE 16
@@ -54,7 +54,7 @@
 #define CALLBACK_LINK_SIZE 32
 #define CALLBACK_LINK_OFFSET 48
 #endif
-#if defined(MODEL_ppc64le)
+#if _CALL_ELF == 2
 #define RESERVED_STACK 32
 #define PARAM_SAVE_AREA 0
 #define LR_SAVE 16
@@ -82,7 +82,7 @@
 
 #endif
 
-#if defined(MODEL_ppc64)
+#if _CALL_ELF == 1
 #define FUNCTION(name) \
   .section ".opd","aw"; \
   .align 3; \
@@ -98,7 +98,7 @@
 
 #endif
 
-#if defined(MODEL_ppc64le)
+#if _CALL_ELF == 2
 #define FUNCTION(name) \
   .section ".text"; \
   .globl name; \
@@ -136,7 +136,7 @@
 
 #endif
 
-#if defined(MODEL_ppc64) || defined(MODEL_ppc64le)
+#if _CALL_ELF == 1 || _CALL_ELF == 2
 
 #define LSYMB(glob) .L##glob
 
@@ -157,7 +157,7 @@
 
 #endif
 
-#if defined(MODEL_ppc64)
+#if _CALL_ELF == 1
         .section ".opd","aw"
 #else
         .section ".text"
@@ -244,7 +244,7 @@ FUNCTION(caml_call_gc)
         stfdu   31, 8(11)
     /* Call the GC */
         bl      caml_garbage_collection
-#if defined(MODEL_ppc64) || defined(MODEL_ppc64le)
+#if _CALL_ELF == 1 || _CALL_ELF == 2
         nop
 #endif
     /* Reload new allocation pointer and allocation limit */
@@ -338,14 +338,14 @@ FUNCTION(caml_c_call)
 #if defined(MODEL_ppc)
         mtctr   28
         bctrl
-#elif defined(MODEL_ppc64)
+#elif _CALL_ELF == 1
         ld      0, 0(28)
         mr      26, 2   /* save current TOC in a callee-save register */
         mtctr   0
         ld      2, 8(28)
         bctrl
         mr      2, 26   /* restore current TOC */
-#elif defined(MODEL_ppc64le)
+#elif _CALL_ELF == 2
         mtctr   28
         mr      12, 28
         mr      26, 2   /* save current TOC in a callee-save register */
@@ -388,7 +388,7 @@ FUNCTION(caml_raise_exn)
         addi    1, 1, -(PARAM_SAVE_AREA + RESERVED_STACK)
                                 /* reserve stack space for C call */
         bl      caml_stash_backtrace
-#if defined(MODEL_ppc64) || defined(MODEL_ppc64le)
+#if _CALL_ELF == 1 || _CALL_ELF == 2
         nop
 #endif
         mr      3, 28           /* restore exn bucket */
@@ -424,7 +424,7 @@ FUNCTION(caml_raise_exception)
         addi    1, 1, -(PARAM_SAVE_AREA + RESERVED_STACK)
                                          /* reserve stack space for C call */
         bl      caml_stash_backtrace
-#if defined(MODEL_ppc64) || defined(MODEL_ppc64le)
+#if _CALL_ELF == 1 || _CALL_ELF == 2
         nop
 #endif
         mr      3, 28           /* restore exn bucket */
@@ -514,14 +514,14 @@ FUNCTION(caml_start_program)
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
@@ -634,7 +634,7 @@ ENDFUNCTION(caml_callback3_exn)
         b       .L102
 ENDFUNCTION(caml_callback3_exn)
 
-#if defined(MODEL_ppc64)
+#if _CALL_ELF == 1
         .section ".opd","aw"
 #else
         .section ".text"
@@ -656,7 +656,7 @@ caml_system__frametable:
 
 /* TOC entries */
 
-#if defined(MODEL_ppc64) || defined(MODEL_ppc64le)
+#if _CALL_ELF == 1 || _CALL_ELF == 2
 
         .section ".toc", "aw"
 
