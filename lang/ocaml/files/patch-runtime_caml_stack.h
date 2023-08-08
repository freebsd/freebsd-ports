--- runtime/caml/stack.h.orig	2019-08-05 17:32:44 UTC
+++ runtime/caml/stack.h
@@ -35,10 +35,10 @@
 #if defined(MODEL_ppc)
 #define Saved_return_address(sp) *((intnat *)((sp) - 4))
 #define Callback_link(sp) ((struct caml_context *)((sp) + 16))
-#elif defined(MODEL_ppc64)
+#elif _CALL_ELF == 1
 #define Saved_return_address(sp) *((intnat *)((sp) + 16))
 #define Callback_link(sp) ((struct caml_context *)((sp) + (48 + 32)))
-#elif defined(MODEL_ppc64le)
+#elif _CALL_ELF == 2
 #define Saved_return_address(sp) *((intnat *)((sp) + 16))
 #define Callback_link(sp) ((struct caml_context *)((sp) + (32 + 32)))
 #else
