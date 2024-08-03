--- singleheader/simdjson.h.orig	2023-12-01 18:56:12 UTC
+++ singleheader/simdjson.h
@@ -6153,15 +6153,15 @@ class base_formatter { (public)
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
