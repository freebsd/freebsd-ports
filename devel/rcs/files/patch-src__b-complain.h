--- src/b-complain.h.orig	2013-04-20 20:08:38.000000000 +0200
+++ src/b-complain.h	2015-02-24 22:01:39.465329000 +0100
@@ -29,12 +29,11 @@
   printf_string (2, 3);
 extern void generic_error (char const *who, char const *fmt, ...)
   printf_string (2, 3);
-extern void generic_fatal (char const *who, char const *fmt, ...)
-  printf_string (2, 3) exiting;
-extern void fatal_syntax (size_t lno, char const *fmt, ...)
-  printf_string (2, 3) exiting;
-extern void fatal_sys (char const *who)
-  exiting;
+extern exiting void generic_fatal (char const *who, char const *fmt, ...)
+  printf_string (2, 3);
+extern exiting void fatal_syntax (size_t lno, char const *fmt, ...)
+  printf_string (2, 3);
+extern exiting void fatal_sys (char const *who);
 
 /* Idioms.  Here, prefix P stands for "program" (general operation);
    M for "manifestation"; R for "repository".  */
