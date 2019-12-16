--- byterun/caml/stack.h.orig	2017-07-13 08:56:44 UTC
+++ byterun/caml/stack.h
@@ -40,10 +40,10 @@
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
