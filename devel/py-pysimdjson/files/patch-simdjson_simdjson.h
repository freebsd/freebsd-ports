--- simdjson/simdjson.h.orig	2024-02-06 03:49:45 UTC
+++ simdjson/simdjson.h
@@ -6223,15 +6223,15 @@ class base_formatter { (public)
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
