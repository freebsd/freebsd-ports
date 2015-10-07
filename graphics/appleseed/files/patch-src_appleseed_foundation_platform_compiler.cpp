--- src/appleseed/foundation/platform/compiler.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed/foundation/platform/compiler.cpp
@@ -43,6 +43,10 @@ const char* Compiler::get_compiler_name(
 #if defined _MSC_VER
     return "Microsoft Visual C++";
 
+// Clang.
+#elif defined __clang__
+    return "clang";
+
 // gcc.
 #elif defined __GNUC__
     return "gcc";
@@ -59,6 +63,12 @@ const char* Compiler::get_compiler_versi
 #if defined _MSC_VER
     return TO_STRING_EVAL(_MSC_VER);
 
+// Clang.
+#elif defined __clang__
+    return TO_STRING_EVAL(__clang_major__) "."
+           TO_STRING_EVAL(__clang_minor__) "."
+           TO_STRING_EVAL(__clang_patchlevel__);
+
 // gcc.
 #elif defined __GNUC__
     return TO_STRING_EVAL(__GNUC__) "."
