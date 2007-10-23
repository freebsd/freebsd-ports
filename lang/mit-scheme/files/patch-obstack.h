
$FreeBSD$

--- obstack.h.orig
+++ obstack.h
@@ -231,7 +231,7 @@
 
 #define obstack_blank_fast(h,n) ((h)->next_free += (n))
 
-#if defined (__GNUC__) && defined (__STDC__)
+#if defined (USE_OBSTACK_MACROS) && defined (__GNUC__) && defined (__STDC__)
 
 /* For GNU C, if not -traditional,
    we can define these macros to compute all args only once
