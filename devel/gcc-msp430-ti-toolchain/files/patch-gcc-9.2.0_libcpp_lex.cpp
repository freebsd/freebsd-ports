This is

  commit cd547f0ddcd3a54e5b73bcda5ac0f0c46808db8b
  Author: Jakub Jelinek <jakub@redhat.com>
  Date:   Sat Sep 26 10:07:41 2020 +0200

which is on the GCC 10 release branch and thus part of lang/gcc10-devel;
we should automatically get it with GCC 10.3.

--- gcc-9.2.0/libcpp/lex.c.orig	2020-11-02 10:24:50 UTC
+++ gcc-9.2.0/libcpp/lex.c
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
