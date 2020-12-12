--- libcpp/lex.c.orig	2020-11-02 10:24:50 UTC
+++ libcpp/lex.c
@@ -531,11 +531,11 @@ init_vectorized_lexer (void)
   search_line_fast = impl;
 }
 
-#elif defined(_ARCH_PWR8) && defined(__ALTIVEC__)
+#elif (GCC_VERSION >= 4005) && defined(_ARCH_PWR8) && defined(__ALTIVEC__)
 
 /* A vection of the fast scanner using AltiVec vectorized byte compares
    and VSX unaligned loads (when VSX is available).  This is otherwise
-   the same as the pre-GCC 5 version.  */
+   the same as the AltiVec version.  */
 
 ATTRIBUTE_NO_SANITIZE_UNDEFINED
 static const uchar *
