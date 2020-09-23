--- include/macros.h.orig	2014-02-22 22:43:58 UTC
+++ include/macros.h
@@ -204,7 +204,7 @@ extern volatile int math_error;
 #define RETURN(VALUE) {RSTSTK(); return (VALUE);}
 #endif /* TRACE_DEPTH not defined */
 
-struct descr _NORET[1];
+extern struct descr _NORET[1];
 #define NORET ((ptr_t)_NORET)
 
 /****************/
