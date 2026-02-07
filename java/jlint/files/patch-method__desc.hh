--- method_desc.hh.orig	2001-02-09 23:40:33 UTC
+++ method_desc.hh
@@ -147,5 +147,5 @@ private:
 
 const char* compound_name(const char* first, const char* second);
 extern string_pool stringPool; // declared in jlint.cc
-extern field_desc* is_const;
+extern field_desc* jlint_is_const;
 #endif
