--- ./include/safe-ctype.h.orig	2013-08-31 13:25:21.000000000 +0100
+++ ./include/safe-ctype.h	2013-08-31 13:25:57.000000000 +0100
@@ -119,6 +119,7 @@
    including another system header (for instance gnulib's stdint.h).
    So we include ctype.h here and then immediately redefine its macros.  */
 
+#if 0
 #include <ctype.h>
 #undef isalpha
 #define isalpha(c) do_not_use_isalpha_with_safe_ctype
@@ -146,5 +147,6 @@
 #define toupper(c) do_not_use_toupper_with_safe_ctype
 #undef tolower
 #define tolower(c) do_not_use_tolower_with_safe_ctype
+#endif
 
 #endif /* SAFE_CTYPE_H */
