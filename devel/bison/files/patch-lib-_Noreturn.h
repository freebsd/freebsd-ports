--- lib/_Noreturn.h.orig	2021-01-23 08:31:48 UTC
+++ lib/_Noreturn.h
@@ -20,7 +20,7 @@
           || (defined _MSC_VER && 1900 <= _MSC_VER)) \
       && 0)
     /* [[noreturn]] is not practically usable, because with it the syntax
-         extern _Noreturn void func (...);
+         _Noreturn extern void func (...);
        would not be valid; such a declaration would only be valid with 'extern'
        and '_Noreturn' swapped, or without the 'extern' keyword.  However, some
        AIX system header files and several gnulib header files use precisely
