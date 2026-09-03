--- simdjson/simdjson.h.orig	2026-09-03 05:57:08 UTC
+++ simdjson/simdjson.h	2026-09-03 05:57:08 UTC
@@ -132,7 +132,7 @@
 #elif defined(__riscv) && __riscv_xlen == 64
 #define SIMDJSON_IS_RISCV64 1
 #elif defined(__PPC64__) || defined(_M_PPC64)
-#if defined(__ALTIVEC__)
+#if defined(__ALTIVEC__) && defined(__POWER8_VECTOR__)
 #define SIMDJSON_IS_PPC64_VMX 1
 #endif // defined(__ALTIVEC__)
 #else
@@ -6223,15 +6223,15 @@
   simdjson_inline void one_char(char c);
 
   simdjson_inline void call_print_newline() {
-      this->print_newline();
+      static_cast<formatter*>(this)->print_newline();
   }
 
   simdjson_inline void call_print_indents(size_t depth) {
-      this->print_indents(depth);
+      static_cast<formatter*>(this)->print_indents(depth);
   }
 
   simdjson_inline void call_print_space() {
-      this->print_space();
+      static_cast<formatter*>(this)->print_space();
   }
 
 protected:
